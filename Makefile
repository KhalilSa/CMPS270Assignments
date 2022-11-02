all: clean makedir my_graph
CC=g++
LIBS=-lm

CFLAGS = -O2 -MD

# distination folder
DIST=bin

my_graph: my_graph.cpp my_graph.hpp
	$(CC) $(CFLAGS) -o bin/my_graph my_graph.cpp $(LIBS)

makedir:
	@mkdir $(DIST)

clean:
	@rm -fr $(DIST)
