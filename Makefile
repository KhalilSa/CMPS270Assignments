all: my_btree
CC=g++
LIBS=-lm

CFLAGS = -O2 -MD

my_btree: my_btree.cpp my_btree.hpp
	$(CC) $(CFLAGS) -o bin/my_btree my_btree.cpp $(LIBS)
