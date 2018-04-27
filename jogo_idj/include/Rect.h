#ifndef Rect_h
#define Rect_h

#include <iostream>
#include "Vec2.h"

class Rect
{
public:
  float x;
  float y;
  float w;
  float h;
  Rect();
  Rect(float x, float y, float w, float h);
  bool Contains(float recebido_x, float recebido_y);
  void Centralize(float recebido_x, float recebido_y);
  Vec2 GetCenter();
private:
};

#endif
