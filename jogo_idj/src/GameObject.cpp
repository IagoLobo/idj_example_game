#include "GameObject.h"

GameObject::GameObject()
{
  isDead = false;
}

GameObject::~GameObject()
{
  int i;
  for (i=components.size()-1; i >= 0; i--)
  {
		delete components[i];
	}
	components.clear();
}

void GameObject::Update(float dt)
{
  int i;
  for (i=0; i<components.size(); i++)
  {
  	components[i]->Update(dt);
  }
}

void GameObject::Render()
{
  int i;
  for (i=0; i<components.size(); i++)
  {
  	components[i]->Render();
  }
}

bool GameObject::IsDead()
{
  return isDead;
}

void GameObject::RequestDelete()
{
  isDead = true;
}

void GameObject::AddComponent(Component* cpt)
{
  components.push_back(cpt);
  if(started)
  {
		cpt->Start();
	}
}

void GameObject::RemoveComponent(Component* cpt)
{
  int i;
  for (i=0; i<components.size(); i++)
  {
  	if(components[i] == cpt)
    {
      components.erase(components.begin()+i-1);
    }
  }
}

Component* GameObject::GetComponent(std::string type)
{
  int i;
  for (i=0; i<components.size(); i++)
  {
  	if(components[i]->Is(type))
    {
      return(components[i]);
    }
  }
  return(nullptr);
}

void GameObject::Start()
{
  int i;
  for(i=0;i<components.size();i++)
  {
    components[i]->Start();
  }

  started = true;
}
