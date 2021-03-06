#ifndef GameObject_h
#define GameObject_h

#include "SDL_include.h"
#include "Component.h"
#include <string>
#include "Rect.h"
#include "Vec2.h"
#include <vector>

class GameObject
{
public:
  GameObject();
  ~GameObject();
  void Update(float dt);
  void Render();
  bool IsDead();
  void RequestDelete();
  void AddComponent(Component* cpt);
  void RemoveComponent(Component* cpt);
  Component* GetComponent(std::string type);
  Rect box;
  void Start();
  bool started = false;
  double angleDeg = 0;

private:
  std::vector <Component*> components;
  bool isDead;
};

#endif
