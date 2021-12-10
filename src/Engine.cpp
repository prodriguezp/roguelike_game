#include "Engine.hpp"
#include "globals/Globals.cpp"

Engine::Engine(/* args */){
  TCODConsole::initRoot(80,50,"Mi primer Roguelike",false);
  player = new Actor(0,0,'@',TCODColor::yellow);
  map = new Map(WIDTH_MAP,HEGHT_MAP);


  //Añadimos un npm
  Actor* npc = new Actor(10,15,'X',TCODColor::white);

  actors.push(player);
  actors.push(npc);

  createRoom(true,20,30,40,50);
}

Engine::~Engine(){
  actors.clearAndDelete();
  delete map;
}
void Engine::Update(){
   TCOD_key_t key;
       TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
       switch(key.vk) {
           case TCODK_UP :
           if(!map->isWall(player->x,player->y-1)){
             player->y--;
           }; break;
           case TCODK_DOWN :
           if(!map->isWall(player->x,player->y+1)){
             player->y++;
           }; break;
           case TCODK_LEFT :
           if(!map->isWall(player->x-1,player->y)){
             player->x--;
           }; break;
           case TCODK_RIGHT:
           if(!map->isWall(player->x+1,player->y)){
             player->x++;
           }; break;
           default:break;
       }

}

void Engine::Render(){
  TCODConsole::root->clear();
       //TCODConsole::root->putChar(player.x,player.y,player.);

       map->render();
       for (Actor* actor : actors)
       {
         actor->render();
       }
       player->render();

       TCODConsole::flush();
}
void Engine::createRoom(bool first, int x1, int y1, int x2, int y2){
  map->dig(x1,y1,x2,y2);
  if(first){
    player->x = x2/2;
    player->y = y2/2;
  }
}
