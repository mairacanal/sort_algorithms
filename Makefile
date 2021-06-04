CC = gcc

CFLAGS = -g -Wall

main: main.o list.o
		$(CC) $(CFLAGS) -o main main.o list.o -lm

main.o: main.c list.h
		$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
		$(CC) $(CFLAGS) -c list.c

clean:
	rm -f *.o
