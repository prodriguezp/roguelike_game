
#include "libtcod.hpp"
#include "Map.hpp"
static const TCODColor darkWall(0,0,100);
static const TCODColor darkGround(50,50,150);

Map::Map(int width, int height) : width(width),height(height){
  //init tiles
  tiles = new Tile[width*height];
  for (int x = 0; x < this->width; x++)
  {
    tiles[x+0*this->width].canWalk = false;
  }

  for (int y = 0; y < this->height; y++)
  {
    tiles[0+y*this->width].canWalk = false;
  }

  for (int x = 0; x < this->width; x++)
  {
    tiles[x+(this->height-1)*this->width].canWalk = false;
  }

  for (int y = 0; y < this->height; y++)
  {
    tiles[(this->width-1)+y*this->width].canWalk = false;
  }

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
