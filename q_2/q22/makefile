CC=gcc
FLAGS=-Wall -g

all: client server

client:client.o
	$(CC) $(FLAGS) -o client.out client.o

client.o: client.c
	$(CC) $(FLAGS) -c client.c

server:server.o
	$(CC) $(FLAGS) -o server.out server.o

server.o: server.c
	$(CC) $(FLAGS) -c server.c

.PHONY:clean all

clean:
	rm -f *.o server.out client.out