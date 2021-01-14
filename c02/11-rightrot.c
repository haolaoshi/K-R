/*
 *
 * Exercise 2-8:
 * Write a funtion rightrot(x,n) that returns the value of the integer x rotaed to the right by n bit postion.
 *
 */

#include <stdio.h>

int rightrot(int x, int n)
{
  return x>>n;
}


main()
{
  int c = 3 ;
  int n = 2 ;
  printf("x = 077, c = %d,rot= %d\n",c , rightrot(077,c));
}
