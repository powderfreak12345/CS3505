// Jonathan Beutler
// CS 3505
// A3

#include <iostream>
#include "Trie.h"

using namespace std;

int main( )
{
  Trie test;
  // test.addAWord("abcdefghijklmnopqrstuvwxyz");
  test.addAWord("dogs");
  cout << "'dogs' in Trie? " << test.isAWord("dogs") << endl;
  cout << "'cats' in Trie? " << test.isAWord("cats") << endl;

}
