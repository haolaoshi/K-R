/*
 *
 * Exercise 5-3. Write a pointer version of the function strcat that we showd in Chapter2: strcat(s,t) copies the string t to the end of s.
 *
 */

#include <stdio.h>

void strcat(char *s, char *t)
{
    while(*s++)
         ;
         s--;
    while(*s++ = *t++)    
        ;

}



main()
{
    char s[100] = "I say:";
    char *t = "How Are You";
    strcat(s,t); 
    printf("%s\r\n",s);
}
