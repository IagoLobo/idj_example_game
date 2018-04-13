#include "Game.h"
#include "State.h"

Game* Game::instance = nullptr;

int allocateChannels = 0;

Game& Game::GetInstance()
{
	if(instance == nullptr)
	{
		instance = new Game("Iago Lobo Ribeiro de Moraes - 14/0082921", 1024, 600);
	}
	return *instance;
}

Game::Game(std::string title, int width, int height)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_Log("Incapaz de inicializar SDL: %s", SDL_GetError());
        exit(1);
    }

    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
    {
    	SDL_Log("Incapaz de inicializar IMG_Init: %s", SDL_GetError());
    	exit(1);
    }

    if(Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) == 0)
    {
    	SDL_Log("Incapaz de inicializar Mix_Init: %s", SDL_GetError());
    	exit(1);
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
    	SDL_Log("Incapaz de inicializar Mix_OpenAudio: %s", SDL_GetError());
    	exit(1);
    }

	allocateChannels = Mix_AllocateChannels(32);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	state = new State();
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

State& Game::GetState()
{
	return *state;
}

SDL_Renderer* Game::GetRenderer()
{
	return renderer;
}

#include <iostream>
void Game::Run()
{
  state->LoadAssets();

	while(!state->QuitRequested())
	{
            //std::cout << "YAY" << std::endl;
		state->Update(0);
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}

	Resources::ClearImages();
	Resources::ClearMusics();
	Resources::ClearSounds();

	delete instance;
}
