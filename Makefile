all: msb_lsb test_driver
CC=gcc
DEPS=main_functions.h main_functions.c

LIBS=-lm

msb_lsb: msb_lsb.c
	$(CC) -o msb_lsb msb_lsb.c $(LIBS)
test_driver: test_driver.c
	$(CC) -o test_driver test_driver.c $(LIBS)