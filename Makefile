all: my_pointers test_driver
CC=gcc
LIBS=-lm

CFLAGS = -O2 -MD

my_pointers: my_pointers.c main_functions.c main_functions.h
	$(CC) $(CFLAGS) -o my_pointers my_pointers.c $(LIBS)
