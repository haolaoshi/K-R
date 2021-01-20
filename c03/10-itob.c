/*
 *
 * Exercise 3-5.
 *      Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
 *      In particular , itob(n,s,16) formats n as a hexadecimal integer in s.
 *
 */


#include <stdio.h>


void reverse(char s[])
{
    int len = strlen(s)- 1;

    char c;
    int i;

    for(i =0; i <= (len/2); i++){
        c = s[len - i];
        s[len- i] = s[i];
        s[i] = c;
    }
printf("%s\n",s);
}

void itob(int n,char s[],int b)
{
    int i  = 0;

    int flag = n;
    if(n < 0) n = -n;
//printf("%d %d\n",n,b);
    do{
        if(n % b >= 10) s[i] = n % b -10 + 'A';
        else s[i] = n % b + '0';
        //printf("%d %c",(n % b),s[i]);
        i++;
    }while((n/= b) > 0);

    if(flag <0) s[i++] = '-';

    s[i] = '\0';
printf("%s\n",s);
    reverse(s);
}


main()
{
    int a = 0777;
    char s[100];
    itob(a,s,8);
    printf("%s\n",s);
}
