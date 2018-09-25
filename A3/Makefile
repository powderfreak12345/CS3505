# Jonathan Beutler
# CS 3505
# A3

CC = g++
CFLAGS = -Wall -std=c++11 -g -fsanitize=address -fsanitize=undefined


TrieTest : TrieTest.cpp Trie.o
	$(CC) $(CFLAGS)  TrieTest.cpp Trie.o -o TrieTest

Trie.o : Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp -I.

Experiments : Experiments.cpp Trie.cpp Trie.h
	$(CC) $(CFLAGS) Experiments.cpp Trie.cpp -o Experiments


clean:
	rm TrieTest Experiments *.o

test:
		./TrieTest "Input1" "Input2"

testExp:
	./Experiments
