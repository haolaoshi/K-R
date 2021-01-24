/*
 *
 */

#include <stdio.h>
#include <ctype.h>
int getch(void);
int ungetch(int);

int getint(int *pn)
{
    int c,sign;
    while(isspace(c = getch()));
    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if( c == '+' || c == '-')
        c = getch();
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

   *pn *= sign;
   if(c != EOF)
        ungetch(c);

   return c;
}

#define SIZE    10
#define BUFFSIZE 100
int bufp = 0;
char buf[BUFFSIZE];
main()
{
    int n,array[SIZE],getint(int *);
    for(n =0 ; n < SIZE && getint(&array[n]) != EOF ; n++);

    return 0;
}


int getch(void)
{

    return (bufp > 0) ? buf[--bufp] : getchar();
}

int ungetch(int c)
{
    if(bufp >= BUFFSIZE)
        printf("ungetch : too many characters.\n");
    else
        buf[bufp++] = c;
}

