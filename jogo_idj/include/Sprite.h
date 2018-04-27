#ifndef Sprite_h
#define Sprite_h

#include <string>
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"
#include "Camera.h"

class Sprite : public Component
{
public:
	Sprite(GameObject& associated);
	Sprite(std::string file, GameObject& associated);
	~Sprite();
	void Open(std::string file);
	void SetClip (int x, int y, int w, int h);
	void Render (int x, int y);
	void Render();
	void Update(float dt);
	bool Is(std::string type);
	int GetWidth();
	int GetHeight();
	bool IsOpen();
	void SetSize(int w, int h);

private:

	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
};

#endif
