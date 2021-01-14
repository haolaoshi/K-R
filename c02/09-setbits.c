/*
 *
 * Exercise 2-6:
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin at postion p set to the rightmost n bits of y,
 * leaving the other bits unchanged.
 *
 *
 */


#include <stdio.h>

/*
 * x save high order bits : ~(~0<<p)&x;
 * x save right most bits : ~(~0<<(y-n))&x;
 * if y > n ： ~(~0<<y) & x & (~0 << (y-n)) << (p-y)
 */
int setbits(unsigned x,int p, int n, int y)
{
    printf("x=%d,p=%d,n=%d,y=%d\n",x,p,n,y);
    unsigned high = (~0<<p) & x;
    unsigned high1 = ~0;
    unsigned  high2 = ~0<<p;
    unsigned high3 = (~0<<p);
    printf("reserved high: 1=%u,2=%u,3=%u\n",high1,high2,high3);
    unsigned rightmost = ~(~0<<(y-n)) & x;
     
    unsigned lefty = ~(~0<<y) & x & (~0 << (y-n));
    unsigned leftx = lefty<<(p-y);
    printf("\nhigh = %d,right = %d,lefty = %d, leftx = %d",high,rightmost,lefty,leftx);
    return high + rightmost + lefty + leftx;
}
/* getbits : get n bits from postion p */
unsigned getbits(unsigned x, int p, int n)
{
    printf("x=%d,p=%d,n=%d\n",x,p,n);
    return (x >> (p+1-n)) & ~(~0 << n);
}

main()
{
  int a = 0102;
  int p , n, y;
  p = 6 , n = 2; y = 3;
  int d;
  //int d = getbits(a,p,n);
  //printbin(d);
  d = setbits(a,p,n,y); 
  printf("\nget n bits from position p : %d\n",d);
}
