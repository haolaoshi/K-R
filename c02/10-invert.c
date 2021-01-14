/*
 *
 * Exercise 2-7:
 * Write a function ivert(x,pn,) that returns x with the n bits that begin at postion p inverted(i.e. 1 changed into 0 and vice versa),
 * levingthe other unchanged).
 */

#include <stdio.h>

int invert(int x,int p, int n)
{
  printf("\nx=%d,p=%d,n=%d",x,p,n);
  int h = ~0<<p & x;
  int l = ~0<<(p-n) && x;
  if(p == n) l = 0;
  int y = ~(~0 << p) & (~x) & (~0 <<(p-n));
  printf("\nHigh=%d,Low=%d,value=%d",h,l,y);

  return h + l + y;
}


main()
{
    int a = 0177;
    int d = invert(a,3,2);
    printf("\nInverted %d to %d",a,d);
}
