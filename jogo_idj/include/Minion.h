#ifndef Minion_h
#define Minion_h

#include "Game.h"
#include "GameObject.h"
#include "Component.h"
#include "Vec2.h"
#include "Sprite.h"
#include "Bullet.h"
#include <memory>

class Minion : public Component
{
public:
	Minion(GameObject& associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
	void Shoot(Vec2 target);
	void SetArc(float n);

private:
	std::weak_ptr<GameObject> alienCenter; /* GameObject& alienCenter; */
	float arc = 0;
};

#endif
