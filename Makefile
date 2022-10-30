all: makedir my_stack
CC=g++
LIBS=-lm

CFLAGS = -O2 -MD

my_stack: my_stack.cpp my_stack.hpp
	$(CC) $(CFLAGS) -o bin/my_stack my_stack.cpp $(LIBS)

makedir:
	@mkdir bin
