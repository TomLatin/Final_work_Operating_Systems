CC=gcc
FLAGS=-Wall -g

all: check_pid

check_pid:check_pid.o
	$(CC) $(FLAGS) -o check_pid.out check_pid.o

check_pid.o: check_pid.c
	$(CC) $(FLAGS) -c check_pid.c

.PHONY:clean all

clean:
	rm -f *.o check_pid.out