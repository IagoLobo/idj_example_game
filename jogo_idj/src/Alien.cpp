#include "Alien.h"
#define PI 3.14
#include <iostream>

Alien::Alien(GameObject& associated, int nMinions) : Component(associated)
{
	Sprite* sprite_alien = new Sprite("assets/img/alien.png", associated);

	associated.box.w = sprite_alien->GetWidth();
	associated.box.h = sprite_alien->GetHeight();
	associated.AddComponent(sprite_alien);

	this->nMinions = nMinions;
}

Alien::~Alien()
{
	minionArray.clear();
}

void Alien::Start()
{
  int i;
	for(i=0; i<nMinions; i++)
  {
		GameObject* go = new GameObject();

		Minion* minion = new Minion(*go, Game::GetInstance().GetState().GetObjectPtr(&associated), 0);
		minion->SetArc((float)i*2*PI/(float)nMinions);

		go->AddComponent(minion);

		minionArray.push_back((Game::GetInstance().GetState().AddObject(go)).lock());
	}
}

void Alien::Update(float dt)
{
	InputManager& input = InputManager::GetInstance();
	speed.x = 0.0;
	speed.y = 0.0;
	float hipo = dt*250.0;

	associated.angleDeg += 3;

  if(input.IsMouseDown(SDL_BUTTON_LEFT))
  {
		taskQueue.push(Action(Action::ActionType::SHOOT, input.GetMouseX() - Camera::pos.x, input.GetMouseY() - Camera::pos.y));
	}

	if(input.IsMouseDown(SDL_BUTTON_RIGHT))
  {
		taskQueue.push(Action(Action::ActionType::MOVE, input.GetMouseX() - Camera::pos.x, input.GetMouseY() - Camera::pos.y));
	}

	if(!taskQueue.empty())
  {
		Action& action = taskQueue.front();

		if(action.type == Action::ActionType::MOVE)
    {
			Vec2 center = associated.box.GetCenter();
			float angle = center.GetAngle(action.pos);

      speed.x = hipo * cos(angle);
			speed.y = hipo * sin(angle);

			if(center.GetDistance(action.pos) < hipo)
      {
				associated.box.Centralize(action.pos.x, action.pos.y);
				taskQueue.pop();
			}
			else
      {
				associated.box.x += speed.x;
				associated.box.y += speed.y;
			}
		}

		if(action.type == Action::ActionType::SHOOT)
    {
			int index = rand()%nMinions;
			float maxDistance = -1;

      int i;
			for(i=0; i<nMinions; i++)
      {
				Vec2 temp = minionArray[i]->box.GetCenter();
				if(temp.GetDistance(action.pos) < maxDistance || maxDistance <= 0)
        {
					maxDistance = temp.GetDistance(action.pos);
					index = i;
				}
			}

			Minion* source = (Minion*) minionArray[index]->GetComponent("minion");
			source->Shoot(action.pos);

			taskQueue.pop();
		}
	}

	if(hp <= 0)
  {
		associated.RequestDelete();
	}
}

void Alien::Render()
{

}

bool Alien::Is(std::string type)
{
  if(type == "alien")
  {
    return true;
  }
  else
  {
    return false;
  }
}

Alien::Action::Action(ActionType type, float x, float y)
{
	this->type = type;
	pos.x = x;
	pos.y = y;
}
