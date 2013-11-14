CC=gcc
LDFLAGS=-lGL
CFLAGS=-g -std=c99
bin=kohonen

all: kohonen

kohonen: main.o data.o
	$(CC) -o $(bin) main.o data.o $(LDFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

data.o: data.c
	$(CC) -c data.c $(CFLAGS)

clean:
	rm -rf *.o

clean-all: clean
	rm -rf $(bin)