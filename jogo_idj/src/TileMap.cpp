#include "TileMap.h"
#include <iostream>
#include <fstream>

TileMap::TileMap (GameObject& associated, std::string file, TileSet* tileSet) : Component(associated)
{
  this->tileSet = tileSet;
  Load(file);
}

void TileMap::Load (std::string file)
{
  std::ifstream map;
	std::string map_string;
	int tileNumber; // O número que representa qual tipo de tile deve ser printado

  map.open(file);
  if(!map.good())
  {
    std::cout << "Error on reading map!" << std::endl;
    exit(1);
  }

  // Lendo os primeiros valores (Width, Height e Depth) do mapa e os setando

	getline(map,map_string,',');
	mapWidth = atoi(map_string.c_str());
	getline(map,map_string,',');
	mapHeight = atoi(map_string.c_str());
	getline(map,map_string,',');
	mapDepth = atoi(map_string.c_str());
	getline(map,map_string,'\n');

  // Lendo o restante do mapa

	while(getline(map,map_string,','))
  {
		tileNumber = atoi(map_string.c_str()) - 1;
		tileMatrix.push_back(tileNumber);
	}

  map.close();
}

void TileMap::SetTileSet(TileSet* tileSet)
{
  this->tileSet = tileSet;
}

int& TileMap::At (int x, int y, int z)
{
  int at = (x + (y * mapWidth) + (z * mapHeight * mapWidth));

  return(tileMatrix[at]);
}

void TileMap::Render()
{
  int i;
  for (i=0; i<mapDepth; i++)
  {
		RenderLayer(i, 0, 0);
	}
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
  int index;
  int i, j;
	float x = 0;
	float y = 0;

	for (i=0; i<mapHeight; i++)
  {
		for (j=0; j<mapWidth; j++)
    {
			index = At(j,i,layer);
      if(index == -1)
      {
        continue;
      }
			tileSet->RenderTile(index, x, y);
			x += tileSet->GetTileWidth();
		}
		x=0;
		y += tileSet->GetTileHeight();
	}
}

int TileMap::GetWidth()
{
  return mapWidth;
}

int TileMap::GetHeight()
{
  return mapHeight;
}

int TileMap::GetDepth()
{
  return mapDepth;
}

void TileMap::Update(float dt)
{

}

bool TileMap::Is(std::string type)
{
  if(type == "tilemap")
  {
    return true;
  }
  else
  {
    return false;
  }
}
