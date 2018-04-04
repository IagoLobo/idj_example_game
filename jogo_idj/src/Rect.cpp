#include "Rect.h"

Rect::Rect()
{
  this->x = 0;
  this->y = 0;
  this->w = 0;
  this->h = 0;
}

Rect::Rect(float x, float y, float w, float h)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

bool Rect::Contains(float recebido_x, float recebido_y)
{
  if((recebido_x > x) && (recebido_x < x + w) &&
     (recebido_y > y) && (recebido_y < y + h))
  {
    return true;
  }
  else
  {
    return false;
  }
}
