#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include<stdio.h>

int main(int argc,char* argv[])
{
    /*Checks if there are 4 arguments, first the name of the executable file ,the second is the pid of the
     *server ,the third is the type of the signal (SIGINT==2,SIGUSR1==10) and the fourth is the amount of
     *the signals
     * */
    if (argc==4 && (atoi(argv[2])==2||atoi(argv[2])==10))
    {
        pid_t serverPid=atoi(argv[1]); //save the server pid
        int times=atoi(argv[3]); //save the amount of the signals
        for (int i = 0; i<times ; ++i)
        {
           kill(serverPid,atoi(argv[2])); //send kill to the server
        }
    }
    else
    {
        printf("Too few arguments or invalid arguments.\n");
    }
    return 0;
}