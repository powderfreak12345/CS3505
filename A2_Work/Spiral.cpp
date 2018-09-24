// Jonathan Beutler
// CS 3505
// A2


#include "Spiral.h"
#include <iostream>
#include <math.h>
using namespace std;



Spiral::Spiral(double centerX, double centerY, double startingRadius, double startingAngle)
              : centerX(centerX), centerY(centerY), radius(startingRadius), angleDeg(startingAngle)
{

  double minStartingRadius = 50;
  if (minStartingRadius > radius)
  {
    radius = minStartingRadius;
  }

  angleRad = angleDeg / 180 * M_PI;

  // Define a starting x and y so that the thing has a place to grow from
  x = centerX + cos(angleRad) * radius;
  y = centerY + sin(angleRad) * radius;

}


double Spiral::getTextX()
{
  return x;
}

double Spiral::getTextY()
{
  return y;
}

double Spiral::getTextAngle()
{
  return angleDeg;
}

Spiral& Spiral::operator++()
{
  radius += 1;
  angleRad -= 15/radius;
  angleDeg = 180 * angleRad / M_PI;

  x = centerX + cos(angleRad) * radius;
  y = centerY + sin(angleRad) * radius;

  return *this;
}

Spiral& Spiral::operator++(int)
{
  radius += 1;
  angleRad -= 15/radius;
  angleDeg = 180 * angleRad / M_PI;

  x = centerX + cos(angleRad) * radius;
  y = centerY + sin(angleRad) * radius;

  return *this;
}

ostream& operator<<(ostream& os, Spiral& s)
{
  os << "X:" << s.x << "  Y:" << s.y << "  Angle:" << s.angleDeg;
  return os;
}
