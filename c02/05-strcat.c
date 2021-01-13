/*
 *
 * strcat:
 * concatenate t to end of s;
 * s must be dig enough */


#include <stdio.h>

void strcat(char s[],char t[])
{
    int i,j;
    i = j = 0;
    while(s[i] != '\0')//find end of s
        i++;

    while((s[i++] = t[j++] ) != '\0')//copy t
        ;
}

main()
{
    char s[] = "what a messAbc!!";
    char b[] = "abc";

    strcat(b,s);

    printf("%s\n",b);
}
