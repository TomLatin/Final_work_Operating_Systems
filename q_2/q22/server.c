#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include<stdio.h>

static int sigintNum=0; //count how much SIGINT we get

/**
 *  The role of this function is to print how many SIGINT signals were actually received on the server
 * @param sig - No use, I accept it because that is how the function I override is built
 */
void sigusr1_handler(int sig)
{
    printf("The number of SIGINT is: %d\n",sigintNum);
}

/**
 * The role of this function is count how many SIGINT signals were actually received on the server
 * @param sig - No use, I accept it because that is how the function I override is built
 */
void sigint_handler(int sig)
{
    sigintNum++;
}

int main(int argc,char* argv[])
{
    printf("Pid of the server: %d\n",getpid());

    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        printf("Error while installing a signal handler.\n");
        exit(EXIT_FAILURE);
    }
    else if(signal(SIGUSR1, sigusr1_handler) == SIG_ERR)
    {
        printf("Error while installing a signal handler.\n");
        exit(EXIT_FAILURE);
    }

    getchar(); //to keep alive, foe end the program enter a character.

}