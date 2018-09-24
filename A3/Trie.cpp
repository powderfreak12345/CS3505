// Jonathan Beutler
// CS 3505
// A3

#include <iostream>
#include "Trie.h"

using namespace std;

Trie::Trie()
{
  for (int i = 0; i < 26; i++)
  {
    subTries[i] = nullptr;
  }
  isWordEnd = false;
}

// Destructor for a Trie
Trie::~Trie()
{
  // Iterate through sub Trie array.  If a Trie exists, delete it.
  for (int i = 0; i < 26; i++)
  {
    if (subTries[i] != nullptr)
    {
      delete subTries[i];
    }
  }
}

void Trie::addAWord(string word)
{
  if (word.length() == 0)
    return; // Empty strings cannot be added to the Trie

  // Convert the first letter to an index usuable in the sub Trie array
  char firstLetter = word[0];
  int firstLetterASCII = firstLetter;
  int firstLetterNormalized = firstLetterASCII - 97;

  if (subTries[firstLetterNormalized] == nullptr)
  {
    subTries[firstLetterNormalized] = new Trie(); // Create a new sub Trie if one does not already exist
  }
  Trie* branchPtr = subTries[firstLetterNormalized];
  // Trie branch = *branchPtr;

  if (word.length() == 1)
  {
    branchPtr->isWordEnd = true;
  }
  else
  {
    string rest = word.substr(1);
    branchPtr->addAWord(rest);  // Recurse on the rest of the word.
  }

}

bool Trie::isAWord(string word)
{
  if (word.length() == 0)
  {
    return false;  // The empty string cannot be in the Trie
  }

  // Convert the first letter to an index usuable in the sub Trie array
  char firstLetter = word[0];
  int firstLetterASCII = firstLetter;
  int firstLetterNormalized = firstLetterASCII - 97;

  Trie* branchPtr = subTries[firstLetterNormalized];
  if (branchPtr == nullptr)
  {
    return false; // The branching for the specified word does not exist
  }
  Trie branch = *branchPtr;

  if (word.length() == 1)
  {
    return branch.isWordEnd;
  }
  else
  {
    string rest = word.substr(1);
    return branch.isAWord(rest);  // Recurse on the rest of the word
  }
}


vector<string> Trie::allWordsStartingWithPrefix(string prefix)
{
  vector<string> ToDo;
  return ToDo; //TODO
}

vector<string> Trie::wordsWithWildCardPrefix(string prefix)
{
  vector<string> ToDo;
  return ToDo; //TODO
}
