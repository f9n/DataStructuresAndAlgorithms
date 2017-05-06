CC=g++

main: main.o util.o
	$(CC) main.o util.o -o main

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

util.o: util.cpp
	$(CC) -c util.cpp -o util.o

clean:
	rm -f *.o main

run:
	./main
