#include "State.h"

State::State()
{
    quitRequested = false;
}

State::~State()
{
	// vazio por hora
}

void State::LoadAssets()
{
	bg.Open("assets/img/ocean.jpg");
        music.Open("assets/audio/stageState.ogg");
        music.Play(-1);
}

void State::Update(float dt)
{
	if(SDL_QuitRequested())
	{
		quitRequested = true;
	}
}

void State::Render()
{
	bg.Render(0, 0); // posições na tela em que ele vai renderizar.

}

bool State::QuitRequested()
{
	return quitRequested;
}