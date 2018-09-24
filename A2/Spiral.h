// Jonathan Beutler
// CS 3505
// A2

#include <iostream>

class Spiral {
  double centerX, centerY, radius;
  float x, y, angleDeg, angleRad;

public:

  Spiral(double centerX, double centerY,
          double startingRadius, double staringAngle);
  double getTextX();
  double getTextY();
  double getTextAngle();

  Spiral& operator++();
  Spiral& operator++(int);

  friend std::ostream& operator<< (std::ostream& os, Spiral& test);
};
