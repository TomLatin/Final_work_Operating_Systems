#define _GNU_SOURCE 500
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> //for atoi
#include <stdio.h> //for perror
#include <stdint.h>
#include <sys/syscall.h>

struct sched_attr {
    uint32_t size;

    uint32_t sched_policy;
    uint64_t sched_flags;

    /* SCHED_NORMAL, SCHED_BATCH */
    uint32_t sched_nice;

    /* SCHED_FIFO, SCHED_RR */
    uint32_t sched_priority;

    /* SCHED_DEADLINE (nsec) */
    uint64_t sched_runtime;
    uint64_t sched_deadline;
    uint64_t sched_period;
};

 int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags)
 {
     return syscall(__NR_sched_setattr, pid, attr, flags);
 }

int main(int argc, char *argv[])
{
    if(argc == 3)
    {
        if(atoi(argv[1])==6)
        {
            struct sched_attr attr;
            unsigned int flags = 0;
            /* Set scheduling properties */
            attr.size = sizeof(attr);
            attr.sched_flags = 0;
            attr.sched_nice = 0;
            attr.sched_priority = atoi(argv[2]);

            /* This creates a 100ms/300ms reservation */
            attr.sched_policy = SCHED_DEADLINE;
            attr.sched_runtime = 100 * 1000 * 1000;
            attr.sched_period = attr.sched_deadline = 300 * 1000 * 1000;

            if(  sched_setattr(0,&attr,flags) == -1)
            {
                perror("sched_setscheduler");
                return 1;
            }
            printf("for To check that the operation worked, please open another terminal and write the following command:\nchrt -p pid\n");
        }
        else
        {
            struct sched_param param;
            param.sched_priority = atoi(argv[2]);
            if( sched_setscheduler(0,atoi(argv[1]),&param) == -1)
            {
                perror("sched_setscheduler");
                return 1;
            }
            printf("for To check that the operation worked, please open another terminal and write the following command:\nchrt -p pid\n");
        }
    }

    printf("the pid is:%d\n",getpid());
    while(1);
}