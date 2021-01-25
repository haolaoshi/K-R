/*
 *
 *
 * POINTER AND ARRAYS
 *
 */


#include <stdio.h>

void swap(int *px,int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int strlen(char *s)
{

    int n;
    for(n = 0; *s != '\0'; s++)
        n++;
    return n;
}

int strlen2(char *s)
{
    char *p = s;
    while(*p != '\0') p++;
    return p - s;
}

void strcpy(char *s,char *t)
{

    int i;
    i = 0;
    while((s[i] = t[i] ) != '\0')
        i++;
}

void strcpy2(char *s,char *t)
{
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}

void strcpy3(char *s,char *t)
{
    while((*s++ = *t++) != '\0')
        ;
}

void strcpy4(char *s,char *t)
{
    while(*s++ = *t++)
        ;
}

int strcmp(char *s,char *t)
{
    int i;
    for(i =0; s[i] == t[i]; i++)
        if(s[i] == '\0') return 0;
    return s[i] - t[i];
}

int strcmp2(char *s,char *t)
{
    for(; *s == *t; s++, t++)
        if(*s == '\0') return 0;
    return *s - *t;
}
