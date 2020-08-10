#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. Uninitialized data segment - BSS */
int primes[] = { 2, 3, 5, 7 };  /* 2. Initialized data segment - data segment D */

static int
square(int x)                   /* 3. text (code segment) */
{
    int result;                 /* 4. Stack */

    result = x * x;
    return result;              /* 5. Return value passed via register */
}

static void
doCalc(int val)                 /* 6. text (code segment) */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. Stack */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* text (code segment) */
{
    static int key = 9973;      /* Initialized data segment */
    static char mbuf[10240000]; /* Uninitialized data segment - BSS */
    char* p;                    /* Stack */


    doCalc(key);

    exit(EXIT_SUCCESS);
}