#include <iostream>

using namespace std;

int main()
{
  // int vals[] = {1, 2, 3};
  int* vals = new int[3];
  vals[3] = 4;
  std::cout << vals[3] << endl;

  // int* val = new int(4);
  // int* same_mem = val;

  // std::cout << *val << *same_mem << std::endl;
  // delete val;
  // delete val;




  return 0;
}
