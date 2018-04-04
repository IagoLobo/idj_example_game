#include "Music.h"

Music::Music()
{
	music = nullptr;
}

Music::Music(std::string file)
{
	music = nullptr;
	Open(file);
}

void Music::Play(int times)
{
	Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop)
{
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file)
{
  music = Mix_LoadMUS(file.c_str());

	if(music == nullptr)
	{
		SDL_Log("Incapaz de inicializar music: %s", Mix_GetError());
		exit(1);
	}
}

bool Music::IsOpen()
{
	if(music != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Music::~Music()
{
	Stop(1500);
	Mix_FreeMusic(music);
}
