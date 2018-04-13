#include "SDL_include.h"
#include "Component.h"

#ifndef Face_h
#define Face_h

class Face : public Component
{
public:
  Face(GameObject& associated);
  ~Face();
  void Damage(int damage);
  void Update(float dt);
  void Render();
  bool Is(std::string type);

private:
  int hitpoints;
};

#endif
