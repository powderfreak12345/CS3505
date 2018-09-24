# Jonathan Beutler
# CS 3505
# A2

CC = g++
CFLAGS = -Wall -std=c++11

# Defines where the top level libharu folder is
LIBHARU = libharu

# -lhpdfs expands to libhpdfs.a
spiralPDF : spiralPDF.o Spiral.o HaruPDF.o
	$(CC) $(CFLAGS) Spiral.o HaruPDF.o spiralPDF.o -o spiralPDF -L$(LIBHARU)/src -lhpdfs

spiralPDF.o : spiralPDF.cpp HaruPDF.h Spiral.h
	$(CC) $(CFLAGS) -c -I$(LIBHARU)/include spiralPDF.cpp

Spiral.o : Spiral.cpp Spiral.h
	$(CC) $(CFLAGS) -c -I$(LIBHARU) Spiral.cpp

HaruPDF.o : HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -c -I$(LIBHARU)/include HaruPDF.cpp


spiralTest.o : spiralTest.cpp Spiral.o
	$(CC) $(CFLAGS) -c -I. spiralTest.cpp

spiralTest : spiralTest.o
	$(CC) $(CFLAGS) -o spiralTest spiralTest.o


clean:
	rm spiralPDF *.o

test:
		./spiralPDF
