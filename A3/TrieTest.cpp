// Jonathan Beutler
// CS 3505
// A3

#include <iostream>
#include <fstream>
#include "Trie.h"

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Incorrect number of arguments.  Exiting." << endl;
    return 1; // Improper argument count
  }

  // Define file names and create file input streams
  string arg1 = argv[1];
  string arg2 = argv[2];
  ifstream input1;
  ifstream input2;

  // Open a file stream for the first argument
  input1.open(arg1);
  if (!input1)
  {
    cout << "Could not open '" << arg1 << "'.  Exiting." << endl;
    return 0; // File not found or could not be opened
  }

  // Create a Trie and add all the words from the file stream
  Trie testTrie;
  string word;
  while (input1 >> word)
  {
    testTrie.addAWord(word);
  }
  input1.close();

  // Open a file stream for the second argument
  input2.open(arg2);
  if (!input2)
  {
    cout << "Could not open '" << arg2 << "'.  Exiting." << endl;
    return 0; // File not found or could not be opened
  }

  // Check all words from the file stream against the Trie
  while (input2 >> word)
  {
    if (testTrie.isAWord(word))
    {
      cout << word << " is found" << endl;
    }
    else
    {
      vector<string> similarWords = testTrie.allWordsStartingWithPrefix(word);
      cout << word << " is not found, did you mean:" << endl;
      if (similarWords.size() == 0)
      {
        cout << "   no alternatives found" << endl;
      }
      else
      {
        for (unsigned int i = 0; i < similarWords.size(); i++)
        {
          cout << "   " << similarWords[i] << endl;
        }
      }
    }
  }

  input2.close();
}
