CC = g++
FLAGS = -O3 -g -Wall
EXECUTABLE = trinary

build: $(EXECUTABLE)

$(EXECUTABLE): Trinary.o NodeTree.o Node.o
	$(CC) $(CFLAGS) -o trinary Trinary.o NodeTree.o Node.o

Trinary.o: Trinary.cpp NodeTree.h Node.h
	$(CC) $(CFLAGS) -c Trinary.cpp

NodeTree.o: NodeTree.cpp NodeTree.h Node.o
	$(CC) $(CFLAGS) -c NodeTree.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

clean:
	rm -f *.o $(EXECUTABLE)

rebuild: clean build