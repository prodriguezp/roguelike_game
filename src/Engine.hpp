#include "libtcod.hpp"
#include "Map.hpp"
#include "Actor.hpp"



#ifndef ROGUELIKE_ENGINE
#define ROGUELIKE_ENGINE


class Engine{
private:
  Map* map;
  TCODList<Actor*> actors;
  Actor* player;
public:
  Engine(/* args */);
  ~Engine();
  void Update();
  void Render();
  void createRoom(bool first, int x1, int y1, int x2, int y2);

};
extern
#endif ROGUELIKE_ENGINE
