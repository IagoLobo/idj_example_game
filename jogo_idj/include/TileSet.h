#ifndef TileSet_h
#define TileSet_h

#include "SDL_include.h"
#include "Sprite.h"
#include <cmath>

class TileSet
{
public:
  TileSet(int tileWidth, int tileHeight, std::string file, GameObject& associated);
  void RenderTile(unsigned index, float x, float y);
  int GetTileWidth();
  int GetTileHeight();

private:
  Sprite tileSet;
  int rows;
  int columns;
  int tileWidth;
  int tileHeight;
};

#endif
