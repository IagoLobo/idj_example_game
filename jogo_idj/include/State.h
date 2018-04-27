#ifndef State_h
#define State_h

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Face.h"
#include "TileMap.h"
#include "InputManager.h"
#include "Camera.h"
#include "CameraFollower.h"
#include <memory>

class State
{
public:
	State();
	~State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();

private:
	//Sprite bg;
	Music music;
	bool quitRequested;

	void AddObject(int mouseX, int mouseY);
	std::vector<std::unique_ptr<GameObject>> objectArray;
};

#endif
