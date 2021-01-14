/*
 *
 * Exercise 3-1.
 * Our binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside).
 * Write a version with only one test inside the loop and measure the difference in run-time.
 *
 * */

#include <stdio.h>

int binsearch(int x, int s[], int n)
{

    int low ,high;
    low = 0;
    high = n - 1;
    int mid = (low + high) /2;
    while(low < high && s[mid] != x){
       if(x < s[mid]) high = mid - 1;
       else low = mid + 1;
    }

}
