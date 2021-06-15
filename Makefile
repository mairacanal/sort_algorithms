CC = gcc
CFLAGS = -g -Wall

all: main

run: all
	./main

main: list.o main.o 
		$(CC) $(CFLAGS) -o main main.o list.o -lm

main.o: main.c 
		$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
		$(CC) $(CFLAGS) -c list.c

clean:
	rm -f *.o main
