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

  cout << "Is the empty string a word?  " << test.isAWord("") << endl;
  cout << "Is 'do' a word?  " << test.isAWord("do") << endl;

  vector<string> vectorTest;

  cout << endl << "Querying all things starting with 'd':" << endl;
  vectorTest = test.allWordsStartingWithPrefix("d");
  for (unsigned int i = 0; i < vectorTest.size(); i++)
  {
    cout << vectorTest[i] << endl;
  }

  cout << endl << "Querying all things starting with 'c':" << endl;
  vectorTest = test.allWordsStartingWithPrefix("c");
  for (unsigned int i = 0; i < vectorTest.size(); i++)
  {
    cout << vectorTest[i] << endl;
  }

  cout << endl << "Querying all things:" << endl;
  vectorTest = test.allWordsStartingWithPrefix("");
  for (unsigned int i = 0; i < vectorTest.size(); i++)
  {
    cout << vectorTest[i] << endl;
  }

  Trie copiedTrie(test);

  cout << endl << "Querying all things from copied Trie:" << endl;
  vectorTest = copiedTrie.allWordsStartingWithPrefix("");
  for (unsigned int i = 0; i < vectorTest.size(); i++)
  {
    cout << vectorTest[i] << endl;
  }

  Trie assignedTrie;
  assignedTrie.addAWord("pigs");
  assignedTrie = test;
  assignedTrie.addAWord("cows");
  cout << endl << "Querying all things from assigned Trie:" << endl;
  vectorTest = assignedTrie.allWordsStartingWithPrefix("");
  for (unsigned int i = 0; i < vectorTest.size(); i++)
  {
    cout << vectorTest[i] << endl;
  }

  cout << endl << "Querying all things from original Trie (make sure nothing changed):" << endl;
  vectorTest = test.allWordsStartingWithPrefix("");
  for (unsigned int i = 0; i < vectorTest.size(); i++)
  {
    cout << vectorTest[i] << endl;
  }



  return 0;
}
