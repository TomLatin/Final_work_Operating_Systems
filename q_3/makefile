CC=gcc
FLAGS=-Wall -g

all: set_policy

set_policy:set_policy.o
	$(CC) $(FLAGS) -o set_policy.out set_policy.o

set_policy.o:set_policy.c
	$(CC) $(FLAGS) -c set_policy.c

.PHONY:clean all

clean:
	rm -f *.o set_policy.out