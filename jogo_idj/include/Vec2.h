#include <iostream>

class Vec2
{
public:
  float x;
  float y;
  Vec2(float x, float y);
  Vec2();
  Vec2& operator+(const Vec2& other);
  Vec2 GetRotated(float rotation);
private:
};
