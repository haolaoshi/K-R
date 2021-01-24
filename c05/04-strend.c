/*
 *
 * Exercise 5-4.
 *      Write the function strend(s,t),which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
 *
 *
 */


#include <stdio.h>

int strend(char *s, char *t)
{
    while(*s++)
        ;
    int len = 0;
    while(*t++)
       len++ ;

    for(s--,t--; *s == *t ;s--,t--,len--)
        ;
    printf("len=%d\r\n",len); 
    return len == -1 ? 1 : 0;
}



main()
{
    char* s = "How Are You";
    char* t = "Y1u";

    printf("is %s in the end of %s ? %d \r\n",t,s,strend(s,t));
}
