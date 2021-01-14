/*
 * binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] 
 *
 */

#include <stdio.h>

int binsearch(int x,int v[],int n)
{
    int low,high,mid;

    low = 0;

    high = n - 1;

    while(low <= high){

        mid = (low + high) / 2;
        if(x < v[mid])
            high = mid  - 1;
        else if(x > v[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return - 1;
}

main()
{
    int v[] = { 1,3,6,5,6,6,3,9,6,3,6,6,6,9,9,6,8};
    
}
