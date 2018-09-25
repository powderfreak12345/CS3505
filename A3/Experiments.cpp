// Jonathan Beutler
// CS 3505

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  cout << "Testing 1 2 3..." << endl;
  vector<string> test1 = {"t0", "t1", "t2"};
  vector<string> test2 = {"t3", "t4", "t5"};

  test1.insert(test1.end(), test2.begin(), test2.end());


  for (int i = 0; i < 6; i++)
  {
    cout << "i: " << i << " " << test1[i] << endl;
  }

  int a = 97;
  char test3 = a;
  cout << test3 << endl;




}
