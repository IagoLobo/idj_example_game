#ifndef Game_h
#define Game_h

#include <string>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Resources.h"
#include "InputManager.h"

class State;
class Game
{
public:
	~Game();
	void Run ();
	SDL_Renderer* GetRenderer ();
	State& GetState();
	static Game& GetInstance();
	float GetDeltaTime();
private:
	Game (std::string title, int width, int height);

	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;

	int frameStart;
	float dt;
	void CalculateDeltaTime();
};

#endif
