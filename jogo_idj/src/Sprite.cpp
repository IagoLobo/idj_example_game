#include "Sprite.h"
#include "Game.h"

Sprite::Sprite()
{
	texture = nullptr;
}

Sprite::Sprite(std::string file)
{
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
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

void Sprite::Render(int x, int y)
{
	SDL_Rect dstrect = {0, 0, width, height};

	SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, 0, nullptr, SDL_FLIP_NONE);
	/*
		Não sei como fazer isso.

		Render é um wrapper para SDL_RenderCopy, que recebe quatro
		argumentos.
		● SDL_Renderer* renderer: O renderizador de Game.
		● SDL_Texture* texture: A textura a ser renderizada;
		● SDL_Rect* srcrect: O retângulo de clipagem. Especifica uma área da
		textura a ser "recortada" e renderizada.
		● SDL_Rect* dstrect: O retângulo destino. Determina a posição na tela
		em que a textura deve ser renderizada (membros x e y). Se os membros
		w e h diferirem das dimensões do clip, causarão uma mudança na
		escala, contraindo ou expandindo a imagem para se adaptar a esses
		valores.
	*/
}

int Sprite::GetWidth()
{
	return width;
}

int Sprite::GetHeight()
{
	return height;
}

bool Sprite::isOpen()
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