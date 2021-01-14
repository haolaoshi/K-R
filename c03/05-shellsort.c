/*
 *
 * Shell Sort invented in 1959 by Shell,
 *
 *
 */

#include <stdio.h>

/*shellsort : sort v[0]...v[n-1] into increasing order */

void shellsort(int v[],int n)
{
    int gap,i,j,temp;
    for(gap = n/2;gap >0; gap /= 2)
        for( i = gap; i <n; i++)
            for(j = i - gap;j >= 0 && v[j] > v[j+gap]; j-= gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }

}
void rintfv(int v[])
{

    int i;

    for(i=0; i <=15; i++)

    printf("%d,",v[i]);
}

main()
{
    int v[] = {1,3,6,5,6,6,3,9,6,3,6,1,7,1,0,6};

    shellsort(v,15);
    rintfv(v);
}
