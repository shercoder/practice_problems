CC = g++
CFLAGS = -O3

default: a.out

a.out: ./array_hopper.cpp.o ./ArrayHopper.cpp.o
	$(CC) $(CFLAGS) -o a.out ./array_hopper.cpp.o ./ArrayHopper.cpp.o $(LIBS)

array_hopper.cpp.o: array_hopper.cpp ArrayHopper.h
	$(CC) $(CFLAGS) -o array_hopper.cpp.o -c array_hopper.cpp

ArrayHopper.cpp.o: ArrayHopper.cpp ArrayHopper.h
	$(CC) $(CFLAGS) -o ArrayHopper.cpp.o -c ArrayHopper.cpp

clean:
	rm -f a.out *.o

rebuild: clean default
