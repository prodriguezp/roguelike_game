#include "libtcod.hpp"


#ifndef ROGUELIKE_ACTOR
#define ROGUELIKE_ACTOR

class Actor
{
  public:
    int x,y;
    int ch;
    TCODColor col;

    Actor(int x, int y, int ch, const TCODColor &col);
    void render() const;
};


#endif ROGUELIKE_ACTOR
