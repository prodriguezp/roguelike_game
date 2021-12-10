#include "libtcod.hpp"
#include "Map.hpp"

static const TCODColor darkWall(0,0,100);
static const TCODColor darkGround(50,50,150);

Map::Map(int width, int height) : width(width),height(height){
  //init tiles
  tiles = new Tile[width*height];
};
Map::~Map(){
    delete[] tiles;
};
bool Map::isWall(int x, int y) const{
  return !tiles[x+y*this->width].canWalk;
};
void Map::render() const{
  for (int x = 0; x < this->width; x++)
  {
    for (int y = 0; y < this->height; y++)
    {
      TCODConsole::root->setCharBackground( x,y,isWall(x,y) ? darkWall : darkGround );
    }
  }

};
void Map::setWall(int x, int y){
  this->tiles[x+y*this->width].canWalk = false;
};

void Map::dig(int xInicial, int yInicial, int xFinal , int yFinal){
  for (int i = xInicial; i <= xFinal; i++)
  {
    for (int j = yInicial; j <= yFinal; j++)
    {
      tiles[i+j*this->width].canWalk = true;

    }

  }

}

