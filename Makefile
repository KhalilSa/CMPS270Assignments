all: clean makedir graph_cycles
CC=g++
LIBS=-lm

CFLAGS = -O2 -MD

# distination folder
DIST=bin

graph_cycles: graph_cycles.cpp graph_cycles.hpp
	$(CC) $(CFLAGS) -o bin/graph_cycles graph_cycles.cpp $(LIBS)

makedir:
	@mkdir $(DIST)

clean:
	@rm -fr $(DIST)
