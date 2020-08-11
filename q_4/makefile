CC=gcc
FLAGS=-Wall -g

all: dir_traversal

dir_traversal:dir_traversal.o
	$(CC) $(FLAGS) -o dir_traversal.out dir_traversal.o

dir_traversal.o: dir_traversal.c
	$(CC) $(FLAGS) -c dir_traversal.c

.PHONY:clean all

clean:
	rm -f *.o dir_traversal.out