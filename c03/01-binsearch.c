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
   int v[] = {1,2,3,4,5,6,7,8,9,10};
   printf(" 5 in 10 = %d \n" , binsearch(5,v,10));

}
