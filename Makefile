all: more_arrays
CC=gcc
LIBS=-lm

CFLAGS = -O2 -MD

more_arrays: more_arrays.c main_functions.c main_functions.h
	$(CC) $(CFLAGS) -o more_arrays more_arrays.c $(LIBS)
