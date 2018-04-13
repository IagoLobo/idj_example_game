#include <iostream>

#ifndef Rect_h
#define Rect_h

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
private:
};

#endif
