CC=g++

main: main.o util.o menu.o
	$(CC) main.o util.o menu.o -o main

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

util.o: util.cpp
	$(CC) -c util.cpp -o util.o

menu.o: menu.cpp
	$(CC) -c menu.cpp -o menu.o

run: main
	./main

clean:
	rm -f *.o main
