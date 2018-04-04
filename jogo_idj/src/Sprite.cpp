#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(GameObject& associated) : Component(associated)
{
	texture = nullptr;
}

Sprite::Sprite(std::string file, GameObject& associated) : Component(associated)
{
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
}

void Sprite::Update(float dt)
{

}

void Sprite::Open(std::string file)
{
	if(texture != nullptr)
	{
    SDL_DestroyTexture(texture);
	}

	texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

	if(texture == nullptr)
        {
            SDL_Log("Incapaz de inicializar texture: %s", SDL_GetError());
            exit(1);
        }

   	if(SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) < 0)
   	{
            SDL_Log("Incapaz de inicializar QueryTexture: %s", SDL_GetError());
            exit(1);
   	}

   	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
	clipRect = {x, y, w, h};
}

void Sprite::Render()
{
	SDL_Rect dstrect = {associated.box.x, associated.box.y, width, height};

	SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, 0, nullptr, SDL_FLIP_NONE);
}

int Sprite::GetWidth()
{
	return width;
}

int Sprite::GetHeight()
{
	return height;
}

bool Sprite::IsOpen()
{
	if(texture != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Sprite::Is(std::string type)
{
	if(type == "sprite")
	{
		return true;
	}
	else
	{
		return false;
	}
}
