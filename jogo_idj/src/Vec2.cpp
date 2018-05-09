#include "Vec2.h"
#include <cmath>

Vec2::Vec2()
{
  this->x = 0;
  this->y = 0;
}

Vec2::Vec2(float x, float y)
{
  this->x = x;
  this->y = y;
}

Vec2 Vec2::GetRotated(float rotation)
{
  Vec2 result;

  result.x = this->x * cos(rotation) - this->y * sin(rotation);
  result.y = this->y * cos(rotation) + this->x * sin(rotation);

  return result;
}

Vec2& Vec2::operator+(const Vec2& other)
{
  this->x += other.x;
  this->y += other.y;

  return *this;
}

Vec2& Vec2::operator-(const Vec2& other)
{
  this->x -= other.x;
  this->y -= other.y;

  return *this;
}

float Vec2::GetDistance(Vec2 vector)
{
  float res = sqrt(pow((this->x - vector.x),2) - pow((this->y - vector.y),2));
  return res;
}

float Vec2::GetAngle(Vec2 vector)
{
  float res = atan2((vector.y - this->y), (vector.x - this->x));
  return res;
}
