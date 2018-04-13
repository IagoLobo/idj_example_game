#include "TileSet.h"
#include <iostream>

TileSet::TileSet (int tileWidth, int tileHeight, std::string file, GameObject& associated) : tileSet(associated)
{
  rows = 0;
  columns = 0;

  this->tileWidth = tileWidth;
  this->tileHeight = tileHeight;
  tileSet.Open(file);

  rows = tileSet.GetHeight()/tileHeight;
  columns = tileSet.GetWidth()/tileWidth;

  tileSet.SetSize(tileWidth, tileHeight);
}

void TileSet::RenderTile(unsigned index, float x, float y)
{
  int totalTiles = rows * columns;

  int aux_x = 0;
	int aux_y = 0;

	if (index < totalTiles && index >= 0)
  {
		aux_x = index % columns;
		aux_y = floor((float)index/(float)columns);

		tileSet.SetClip(aux_x * tileWidth, aux_y * tileHeight, tileWidth, tileHeight);
		tileSet.Render(x, y);
	}
  else
  {
    std::cout << "Invalid TileSet Index!" << std::endl;
    exit(1);
  }
}

int TileSet::GetTileWidth()
{
  return tileWidth;
}

int TileSet::GetTileHeight()
{
  return tileHeight;
}
