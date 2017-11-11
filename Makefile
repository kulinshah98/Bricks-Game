CC=g++
all: mygame
FLAGS= -lGL -lGLU -lGLEW -lglut
OPTS=-I"irrKlang-64bit-1.5.0/include" -L"/usr/lib" irrKlang-64bit-1.5.0/bin/linux-gcc-64/libIrrKlang.so -pthread
mygame: main.o not_useful.o variables.o canon.o bricks.o baskets.o laser.o mirror.o collision.o
	$(CC) -o mygame not_useful.o main.o variables.o canon.o bricks.o baskets.o laser.o mirror.o collision.o $(FLAGS) $(OPTS)

not_useful.o: not_useful.cpp not_useful.h
	$(CC) -c not_useful.cpp $(FLAGS)

main.o: main.cpp main.h
	$(CC) -c main.cpp $(FLAGS) $(OPTS)

variables.o: variables.cpp
	$(CC) -c variables.cpp $(FLAGS)

canon.o: canon.cpp canon.h
	$(CC) -c canon.cpp $(FLAGS)

bricks.o: bricks.cpp bricks.h
	$(CC) -c bricks.cpp $(FLAGS)

baskets.o: baskets.cpp baskets.h
	$(CC) -c baskets.cpp $(FLAGS)

laser.o: laser.cpp laser.h
	$(CC) -c laser.cpp $(FLAGS)

mirror.o: mirror.cpp mirror.h
	$(CC) -c mirror.cpp $(FLAGS)

collision.o: collision.cpp collision.h
	$(CC) -c collision.cpp $(FLAGS)

clean:
	rm *.o
