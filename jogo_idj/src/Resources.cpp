#include "Game.h"
#include "Resources.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file)
{
	SDL_Texture* textura;
	std::unordered_map<std::string,SDL_Texture*>::const_iterator table_img = imageTable.find (file);

	if(table_img == imageTable.end())
  {
		textura = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
		if (textura == nullptr)
    {
	    	SDL_Log("Unable to initialize texture: %s", SDL_GetError());
	    	exit(1);
		}

		imageTable.emplace(file, textura);
	}
	else
  {
		textura = table_img->second;
	}

	return(textura);
}

void Resources::ClearImages ()
{
	std::unordered_map<std::string,SDL_Texture*>::const_iterator table_img;

	for(table_img = imageTable.begin(); table_img != imageTable.end(); table_img++)
  {
		SDL_DestroyTexture(table_img->second);
	}

	imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file)
{
	Mix_Music* music_r;
	std::unordered_map<std::string,Mix_Music*>::const_iterator table_music = musicTable.find (file);

	if(table_music == musicTable.end())
  {
		music_r = Mix_LoadMUS(file.c_str());
		if (music_r == nullptr){
	    	SDL_Log("Unable to initialize chunk: %s", Mix_GetError());
	    	exit(1);
		}

		musicTable.emplace(file, music_r);
	}
	else
  {
		music_r = table_music->second;
	}

	return(music_r);
}

void Resources::ClearMusics (){

  std::unordered_map<std::string,Mix_Music*>::const_iterator table_music;

	for(table_music = musicTable.begin(); table_music != musicTable.end(); table_music++)
  {
		Mix_FreeMusic(table_music->second);
	}

	musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file)
{
	Mix_Chunk* sound_r;
	std::unordered_map<std::string,Mix_Chunk*>::const_iterator table_sound = soundTable.find (file);

	if(table_sound == soundTable.end())
  {
		sound_r = Mix_LoadWAV(file.c_str());
		if (sound_r == nullptr)
    {
	    	SDL_Log("Unable to initialize chunk: %s", Mix_GetError());
	    	exit(1);
		}

		soundTable.emplace(file, sound_r);
	}
	else
  {
		sound_r = table_sound->second;
	}

	return(sound_r);
}

void Resources::ClearSounds ()
{
	std::unordered_map<std::string,Mix_Chunk*>::const_iterator table_sound;

	for (table_sound = soundTable.begin(); table_sound != soundTable.end(); table_sound++)
  {
		Mix_FreeChunk(table_sound->second);
	}

	soundTable.clear();
}
