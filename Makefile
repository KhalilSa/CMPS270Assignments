all: my_arrays test_driver
CC=gcc
LIBS=-lm

CFLAGS = -O2 -MD

my_arrays: my_arrays.c main_functions.c main_functions.h
	$(CC) $(CFLAGS) -o my_arrays my_arrays.c $(LIBS)
test_driver: test_driver.c main_functions.c main_functions.h
	$(CC) $(CFLAGS) -o test_driver test_driver.c $(LIBS)
