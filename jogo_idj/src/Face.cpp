#include "Face.h"
#include "GameObject.h"
#include "Sound.h"
#include <iostream>

Face::Face(GameObject& associated) : Component(associated)
{
  hitpoints = 30;
}

Face::~Face()
{

}

void Face::Damage(int damage)
{
  hitpoints -= damage;

  if(hitpoints <= 0)
  {
    std::cout << "HITPOINTS <= 0!" << std::endl;
    associated.RequestDelete();
    Sound* sound_aux = dynamic_cast<Sound*>(associated.GetComponent("sound"));
    if(sound_aux != nullptr)
    {
      sound_aux->Play(1);
      std::cout << "Tocou som de morte!" << std::endl;
    }
  }
}

void Face::Update(float dt)
{

}

void Face::Render()
{

}

bool Face::Is(std::string type)
{
  if(type == "face")
  {
    return true;
  }
  else
  {
    return false;
  }
}
