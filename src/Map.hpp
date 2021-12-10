#include "libtcod.hpp"


#ifndef ROGUELIKE_MAP
#define ROGUELIKE_MAP

struct Tile{
  bool canWalk; // can we walk through this tile?
  Tile() : canWalk(false) {}
};

class Map{
public :
   int width,height;

   Map(int width, int height);
   ~Map();
   bool isWall(int x, int y) const;
   void render() const;
   void setWall(int x, int y);
   void dig(int xInicial, int yInicial, int xFinal , int yFinal);

protected :
   Tile *tiles;


};

#endif ROGUELIKE_MAP
