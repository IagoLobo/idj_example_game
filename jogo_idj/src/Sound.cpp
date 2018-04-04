#include "Sound.h"

Sound::Sound(GameObject& associated) : Component(associated)
{
  chunk = nullptr;
}

Sound::Sound(GameObject& associated, std::string file) : Component(associated)
{
  Open(file);
}

Sound::~Sound()
{
  while(!Mix_Playing(channel))
  {
    if(chunk != nullptr)
    {
        Mix_HaltChannel(channel);
        Mix_FreeChunk(chunk);
    }
  }
}

void Sound::Play(int times)
{
  channel = Mix_PlayChannel(-1, chunk, times-1);
}

void Sound::Stop()
{
  if(chunk != nullptr)
  {
    Mix_HaltChannel(channel);
  }
}

void Sound::Open(std::string file)
{
  chunk = Mix_LoadWAV(file.c_str());

  if(chunk == nullptr)
  {
    SDL_Log("Unable to initialize chunk: %s", Mix_GetError());
    exit(1);
  }
}

bool Sound::IsOpen()
{
  if(chunk != nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Sound::Update(float dt)
{

}

void Sound::Render()
{

}

bool Sound::Is(std::string type)
{
  if(type == "sound")
  {
    return true;
  }
  else
  {
    return false;
  }
}
