CC=gcc
LDFLAGS=-L ./lib/ -lcsfml-system -lcsfml-window -lcsfml-graphics -lopengl32
CFLAGS=-g -std=c99 -Wall -I ./include/
bin=kohonen

all: kohonen

kohonen: main.o data.o neuron.o
	$(CC) -o bin/$(bin) main.o data.o neuron.o $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

data.o: data.c data.h
	$(CC) -c data.c $(CFLAGS)

neuron.o: neuron.c neuron.h
	$(CC) -c neuron.c $(CFLAGS)

clean:
	rm -rf *.o

clean-all: clean
	rm -rf $(bin)