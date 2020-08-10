#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include<stdio.h>

int main(int argc,char* argv[])
{
    //Checks if there are 2 arguments, first the name of the executable file and the second is the pid
    if(argc == 2)
    {
        pid_t pid=atoi(argv[1]); //save the pid
        int flag= kill(pid,0); //save the return value from the kill function
        if(flag==0) //success
            printf("exists.\n");
        else if(flag==-1) //fail
        {
            //errno define by the kill function 
            if(errno==EPERM)
                printf("exists but we have no permission.\n");
            else if(errno==ESRCH)
                printf("does not exist.\n");
        }
    }
    else
    {
        printf("Too few arguments, please enter pid.\n");
    }
    return 0;
}