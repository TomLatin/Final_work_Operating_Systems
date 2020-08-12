Read Me:
In order to compile, enter the appropriate folder on your computer by command:
cd [path]
When you are in the correct folder on your computer you should type: make
and two files will be built: server.out client.out
In order to run the program please open 2 terminals and do the following:
In the first terminal execute:
./server.out
After running the program, the server's Pid will be printed for you as follows:
Pid of the server: xxx, where xxx is the Pid of the server.
In the second terminal write:
./client.out [server Pid] [2 | 10] [number of signals]
Where 2 is SIGINT and 10 is SIGUSR1.
To delete the files created during file construction you can execute the command: make clean
To stop the server enter any character.
