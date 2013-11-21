CC=gcc
LDFLAGS=-L ./lib/ -lglut32 -lopengl32 
CFLAGS=-g -std=c99 -Wall -I ./include/
bin=kohonen

all: kohonen

kohonen: base_opengl.o data.o neuron.o
	$(CC) -o bin/$(bin) base_opengl.o data.o neuron.o $(LDFLAGS)

base_opengl.o: base_opengl.c base_opengl.h
	$(CC) -c base_opengl.c $(CFLAGS)

data.o: data.c data.h
	$(CC) -c data.c $(CFLAGS)

neuron.o: neuron.c neuron.h
	$(CC) -c neuron.c $(CFLAGS)

clean:
	rm -rf *.o

clean-all: clean
	rm -rf $(bin)