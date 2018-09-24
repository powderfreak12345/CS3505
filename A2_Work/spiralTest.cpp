// Jonathan Beutler
// CS 3505
// A2

#include "Spiral.cpp"
#include <iostream>

int main()
{
  Spiral s = Spiral(0, 0, 100, 90);

  std::cout << "Initial measurements" << endl;
  std::cout << s << endl;

  std::cout << endl << "Subtracting 10 degrees using s++" << endl;
  s++;
  std::cout << s << endl;

  std::cout << endl << "Subtracting 10 degrees using ++s" << endl;
  ++s;
  std::cout << s << endl;
}
