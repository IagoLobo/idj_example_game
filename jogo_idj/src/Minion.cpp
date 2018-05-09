#include "Minion.h"
#define PI 3.14

Minion::Minion(GameObject& associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated)
{
  Sprite* sprite_minion = new Sprite("assets/img/minion.png", associated);
	associated.box.w = sprite_minion->GetWidth();
	associated.box.h = sprite_minion->GetHeight();

	int random = rand() % 6;
	float temp = 1.0 + ((float)random/10);
	sprite_minion->SetScaleX(temp, temp);

	associated.AddComponent(sprite_minion);

	this->alienCenter = alienCenter;
}

void Minion::Update(float dt)
{
	std::shared_ptr<GameObject> alien;
	alien = alienCenter.lock();

	if(!alien)
  {
		associated.RequestDelete();
		return;
	}

	Vec2 center = alien->box.GetCenter();

	Vec2 pos = Vec2(200, 0).GetRotated(arc) + Vec2(center.x, center.y);
	arc+=PI/200;

	associated.box.Centralize(pos.x, pos.y);

  associated.angleDeg -= 3;
}

void Minion::SetArc(float n)
{
	arc = n;
}

void Minion::Render()
{

}

bool Minion::Is(std::string type)
{
  if(type == "minion")
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Minion::Shoot(Vec2 target)
{
	GameObject* go = new GameObject();
	go->box.Centralize(associated.box.GetCenter().x, associated.box.GetCenter().y);
	float angle = associated.box.GetCenter().GetAngle(target);

	Bullet* bullet = new Bullet(*go,(double)angle, 350.0, 30, associated.box.GetCenter().GetDistance(target)*2,"assets/img/minionbullet1.png");
	go->AddComponent(bullet);
	Game::GetInstance().GetState().AddObject(go);
}
