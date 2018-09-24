# Jonathan Beutler
# CS 3505
# A3

CC = g++
CFLAGS = -Wall -std=c++11 -g


TrieTest : TrieTest.cpp Trie.o
	$(CC) $(CFLAGS)  TrieTest.cpp Trie.o Node.o -o TrieTest

Trie.o : Trie.cpp Trie.h Node.o
	$(CC) $(CFLAGS) -c Trie.cpp -I.

Node.o : Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp -I.


clean:
	rm TrieTest *.o

test:
		./TrieTest
