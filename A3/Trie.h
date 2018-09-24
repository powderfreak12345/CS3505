// Jonathan Beutler
// CS 3505
// A3

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>
#include "Node.h"

class Trie {

private:
  bool isWordEnd;
  Trie* subTries[26];

public:
  Trie();
  ~Trie();
  void addAWord(std::string word);
  bool isAWord(std::string word);
  std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);
  std::vector<std::string> wordsWithWildCardPrefix(std::string prefix);
};

#endif
