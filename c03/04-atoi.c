/*
 *
 * ex. Here is another version of atoi for converting a string to its numberic equivalent.
 *
 */


#include <stdio.h>

/*atoi: convert s to integer ; version 2 */


int atoi(char s[])
{
    int i,n,sign;
    for(i=0; isspace(s[i]);i++) 
        ;//skip white space
    sign = (s[i] == '-') ? - 1 : 1;

    if(s[i] == '+' || s[i] == '-')
        i++; // skip sign

    for(n =0; isdigit(s[i]);i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}


main()
{
    char s[1000];
    int i = 0;
    int c = 0;
    while((c = getchar()) != EOF ){
        s[i] = c;
        i++;
    } 
    printf("data : %d\n",atoi(s));
}
