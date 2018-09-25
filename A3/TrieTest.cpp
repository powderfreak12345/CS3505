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
  test.addAWord("d");
  test.addAWord("dogs");
  test.addAWord("doughnuts");
  test.addAWord("doug");
  test.addAWord("cats");

  vector<string> fuckYouTest;

  cout << "Querying all things starting with 'd':" << endl;
  fuckYouTest = test.allWordsStartingWithPrefix("d");
  for (unsigned int i = 0; i < fuckYouTest.size(); i++)
  {
    cout << fuckYouTest[i] << endl;
  }

  cout << endl << "Querying all things starting with 'c':" << endl;
  fuckYouTest = test.allWordsStartingWithPrefix("c");
  for (unsigned int i = 0; i < fuckYouTest.size(); i++)
  {
    cout << fuckYouTest[i] << endl;
  }

  cout << endl << "Querying all things:" << endl;
  fuckYouTest = test.allWordsStartingWithPrefix("");
  for (unsigned int i = 0; i < fuckYouTest.size(); i++)
  {
    cout << fuckYouTest[i] << endl;
  }






}
