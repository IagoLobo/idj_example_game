#ifndef Component_h
#define Component_h

#include <string>
#include "SDL_include.h"

class GameObject;

class Component
{
public:
  Component(GameObject& associated);
  virtual ~Component();
  void virtual Update(float dt) = 0;
  void virtual Render() = 0;
  bool virtual Is(std::string type) = 0;
  void virtual Start();
protected:
  GameObject& associated;
private:
};

#endif
