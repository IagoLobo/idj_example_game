#ifndef Vec2_h
#define Vec2_h

#include <iostream>

class Vec2
{
public:
  float x;
  float y;
  Vec2(float x, float y);
  Vec2();
  Vec2& operator+(const Vec2& other);
  Vec2& operator-(const Vec2& other);
  Vec2 GetRotated(float rotation);
  float GetDistance(Vec2 vector);
  float GetAngle(Vec2 vector);
  
private:
};

#endif
