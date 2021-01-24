/*
 *
 * Exercise 5-5.
 *
 *      Write versions of the library functions strncpy,strncat,and strncmp,
 *      Which operate on at most the first n characters of their argument
 *      strings, For example ,strncpy(s,t,n) copies at most n characters of t to s.
 *      Full descriptions are in Appendix B.
 *
 */

#include <stdio.h>

void strncpy(char* s, char* t, int n)
{
   while((n-- > 0) && ( *s++ = *t++))
        ;
}

void strncat(char* s,char* t,int n)
{
    while(*s++)
        ;
    s--;
    while((n-- >0) && ( *s++ = *t++))
        ;
}

int strncmp(char* s,char* t,int n)
{
    while(n >0 && *t++)
       n-- ;

    if(!*t) return 0;
    for(; *t++ == *s++; )
        ;
    return *s - *t;
}

int strncmp1(char *s,char* t)
{
    for(; *s == *t; s++,t++)
        if(*s == '\0') return 0;
    return *s - *t;
}
void strcpy1(char *s,char *t)
{
    while(*s++ = *t++)
        ;
}

main()
{
    char s[20] = "001234CAn you Spell?";
    char* t = "1234";
    strncpy(s,t,2);
    printf("strncpy %s\r\n",s);
    strncat(s,t,2);
    printf("strncat %s\r\n",s);
    printf("is %s cmp %s ? %d\r\n",s,t,strncmp(s,t,2));
}
