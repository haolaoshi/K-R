/*
 *
 *
 * a pseudo-random number genearator and a function for initializing the seed;
 *
 * the former illustrates a cast;
 */


#include <stdio.h>

unsigned long int next = 1;


int rand(void)
{
    next = next  * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

void srand(unsigned int seed)
{
    next = seed;
}

main()
{

    srand(1);
    printf("%ul",rand());
}
