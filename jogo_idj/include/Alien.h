#ifndef Alien_h
#define Alien_h

#define INCLUDE_SDL
#include "SDL_include.h"
#include "Component.h"
#include "Game.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Vec2.h"
#include "InputManager.h"
#include "Camera.h"
#include "Minion.h"
#include <memory>
#include <queue>

class Alien : public Component
{
public:
	Alien(GameObject& associated, int nMinions);
	~Alien();

	void Start();
	void Update(float dt);
	void Render();
	bool Is(std::string type);

private:
	class Action
  {
	public:
		typedef enum ActionType {MOVE, SHOOT} ActionType;
		Action(ActionType type, float x, float y);
		ActionType type;
		Vec2 pos;
	};

	Vec2 speed;
	int hp = 100;
	int nMinions;
	std::queue<Action> taskQueue;
	std::vector<std::shared_ptr<GameObject>> minionArray;
};

#endif
