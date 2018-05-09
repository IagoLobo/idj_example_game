#include "Bullet.h"
#include <iostream>

Bullet::Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite) : Component(associated)
{
  Sprite* sprite_bullet = new Sprite(sprite, associated);
	associated.box.w = sprite_bullet->GetWidth();
	associated.box.h = sprite_bullet->GetHeight();

	associated.AddComponent(sprite_bullet);

	this->damage = damage;
	distanceLeft = maxDistance;
  this->speed.x = speed * cos(angle);
	this->speed.y = speed * sin(angle);
}

void Bullet::Update(float dt)
{
	int timeSpeed = sqrt(pow(speed.x,2) - pow(speed.y,2));

	associated.box.x += speed.x * dt;
	associated.box.y += speed.y * dt;

	distanceLeft -= timeSpeed * dt;

	if (distanceLeft <= 0)
  {
		associated.RequestDelete();
	}
}

void Bullet::Render()
{

}

bool Bullet::Is(std::string type)
{
	if(type == "bullet")
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Bullet::GetDamage()
{
	return damage;
}
