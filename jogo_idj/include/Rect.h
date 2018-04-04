#include <iostream>

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
