CC=g++
all: mygame
mygame: main.o not_useful.o variables.o canon.o bricks.o baskets.o laser.o mirror.o collision.o
	$(CC) -o mygame not_useful.o main.o variables.o canon.o bricks.o baskets.o laser.o mirror.o collision.o -lGL -lGLU -lGLEW -lglut

not_useful.o: not_useful.cpp not_useful.h
	$(CC) -c not_useful.cpp -lGL -lGLU -lGLEW -lglut

main.o: main.cpp main.h
	$(CC) -c main.cpp -lGL -lGLU -lGLEW -lglut

variables.o: variables.cpp
	$(CC) -c variables.cpp -lGL -lGLU -lGLEW -lglut

canon.o: canon.cpp canon.h
	$(CC) -c canon.cpp -lGL -lGLU -lGLEW -lglut

bricks.o: bricks.cpp bricks.h
	$(CC) -c bricks.cpp -lGL -lGLU -lGLEW -lglut

baskets.o: baskets.cpp baskets.h
	$(CC) -c baskets.cpp -lGL -lGLU -lGLEW -lglut

laser.o: laser.cpp laser.h
	$(CC) -c laser.cpp -lGL -lGLU -lGLEW -lglut

mirror.o: mirror.cpp mirror.h
	$(CC) -c mirror.cpp -lGL -lGLU -lGLEW -lglut

collision.o: collision.cpp collision.h
	$(CC) -c collision.cpp -lGL -lGLU -lGLEW -lglut

clean:
	rm main.o variables.o not_useful.o canon.o bricks.o baskets.o laser.o mirror.o collision.o
