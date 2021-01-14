/*
 *
 * Assignment Operators and Expressons;
 *
 *
 * Exercise 2-9:
 * In a two 's complement number system , x &= (x- 1) deletes the rightmost 1 bit in x;
 * 
 *
 */


#include <stdio.h>

/* bitcount: count 1 bits in x */

int bitcount(unsigned x)
{
    int b;

    for(b = 0; x != 0; x >>= 1)
        if (x & 01) b++;
    return b;
}

int completion(int x)
{
    return x &= (x-1);
}
//a faster verion of bit count
int bitcount2(unsigned x)
{
   int b;
   for(b=0; x !=0 ; x &=(x - 1)){
      b++;
    }
   return b;
}
main()
{

    int x = 0177;

    printf("\n%d contbit = %d",x,bitcount(x));
    printf("\nCompetion = %d ",completion(x));
    printf("\nbitCount2 = %d ",bitcount2(x));
}
