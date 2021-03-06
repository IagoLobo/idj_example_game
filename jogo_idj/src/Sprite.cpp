#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(GameObject& associated) : Component(associated)
{
	texture = nullptr;
	scale.x = 1;
	scale.y = 1;
	angle = 0;
}

Sprite::Sprite(std::string file, GameObject& associated) : Component(associated)
{
	texture = nullptr;
	scale.x = 1;
	scale.y = 1;
	angle = 0;
	Open(file);
}

Sprite::~Sprite()
{
	//SDL_DestroyTexture(texture);
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

	//texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
	texture = Resources::GetImage(file.c_str());

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
	SDL_Rect dstrect = {associated.box.x + Camera::pos.x,
											associated.box.y + Camera::pos.y,
											clipRect.w * scale.x,
											clipRect.h * scale.y};

	angle = associated.angleDeg;

	SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, angle, nullptr, SDL_FLIP_NONE);

	//Render(associated.box.x + Camera::pos.x, associated.box.y + Camera::pos.y);
}

void Sprite::Render(int x, int y)
{
	SDL_Rect dstrect = {x, y, width, height};

	SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, 0, nullptr, SDL_FLIP_NONE);
}

void Sprite::SetSize(int w, int h)
{
	this->width = w;
	this->height = h;
}

int Sprite::GetWidth()
{
	return width * scale.x;
}

int Sprite::GetHeight()
{
	return height * scale.y;
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

void Sprite::SetScaleX(float scaleX, float scaleY)
{
	if(scaleX != 0)
	{
		scale.x = scaleX;
	}

	if(scaleY != 0)
	{
		scale.y = scaleY;
	}

	Vec2 temp = associated.box.GetCenter();

	associated.box.w *= scaleX;
	associated.box.h *= scaleY;
	associated.box.Centralize(temp.x,temp.y);
}

Vec2 Sprite::GetScale()
{
	return scale;
}
