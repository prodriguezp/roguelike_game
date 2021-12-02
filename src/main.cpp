#include "libtcod.hpp"
#include "Actor.hpp"

int main() {
   Actor player (25,25,'@',TCODColor::blue);

   TCODConsole::initRoot(80,50,"libtcod C++ tutorial",false);
   while ( !TCODConsole::isWindowClosed() ) {
       TCOD_key_t key;
       TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);
       switch(key.vk) {
           case TCODK_UP : player.y--; break;
           case TCODK_DOWN : player.y++; break;
           case TCODK_LEFT : player.x--; break;
           case TCODK_RIGHT : player.x++; break;
           default:break;
       }
       TCODConsole::root->clear();
       //TCODConsole::root->putChar(player.x,player.y,player.);
       player.render();
       TCODConsole::flush();
   }
   return 0;
}
