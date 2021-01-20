/*
 *
 *
 * Exercise 3-4:
 *      In a two's complement number representation,our version of itoa does not
 *      handle the largest negative number,that is, the value of n equal to -(2
 *      ^wordsize - 1) 
 *      Explain why not, Modify it to print that value correctly,
 *      regardless of the machine on which it runs.
 */

#include <stdio.h>


void reverse(char s[])
{
    int i =0;
    int len = strlen(s) - 1;
    char c ;

    for(i =0; i <= (len/2);i++){
        c = s[len - i] ;
        s[len - i] = s[i];
        s[i] = c;
    }

}

void itoa(int n, char s[])
{
    int i,sign;

    if((sign - n) < 0)
        n = -n;

    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);

    if(sign < 0) 
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

main()
{
    double a = 2.001e15;
    char s[100];
    printf("%.0f\n",a);
    itoa(a,s);
    printf("%s\n",s);
}
