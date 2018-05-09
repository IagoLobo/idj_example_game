#ifndef Bullet_h
#define Bullet_h

#include "GameObject.h"
#include "Component.h"
#include "Vec2.h"
#include "Sprite.h"
#include <memory>

class Bullet : public Component
{
public:
	Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
	int GetDamage();

private:
	Vec2 speed;
	float distanceLeft;
	int damage;
};

#endif
