CC=g++

all:
	mkdir -p obj
	@echo "Created Obj File!"

compile:	bin/main

help:
	@echo "make compile   : compile source code"
	@echo "make run       : compiler source code and run"
	@echo "make clean     : delete all obj file and executable file."
	@echo "Before compiler source code, you should create obj directory with this command: make all"

bin/main: obj/main.o obj/util.o obj/menu.o
	$(CC) obj/main.o obj/util.o obj/menu.o -o bin/main

obj/main.o: src/main.cpp
	$(CC) -c src/main.cpp -o obj/main.o

obj/util.o: src/util.cpp
	$(CC) -c src/util.cpp -o obj/util.o

obj/menu.o: src/menu.cpp
	$(CC) -c src/menu.cpp -o obj/menu.o

run: bin/main
	./bin/main

clean:
	rm -f obj/* bin/main
