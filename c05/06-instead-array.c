/*
 *
 * Exercise 5-6.
 *      Instead of array indexing, Good possibiliteies include 
 *      getaline, atoi,itoa,reverse and strindex , getop 
 *
 *
 */



#include <stdio.h>
#define DEBUG   1 

int getaline(char* str,int max)
{
    int len = 0;
    for(len = max - 1; len > 0 && (*str = getchar()) != EOF && (*str != '\n'); len--,str++)
        ;
    *str = '\0';
    return max - len; 
}


void reverse(char* s)
{
   char* p;
   p = s;
  
   while(*s++) 
     ;
   *--s = '\0';
   s--;
   char c;
   int n = (s - p ) /2 + 1;
   for(; n > 0 && (c = *s)  && (*s = *p) && (*p = c);n--,s--,p++)
if(DEBUG)    printf("%c , %c , %c \n",c , *s, *p);
   
}
int atoi(char* str)
{
    int n = 0;
    reverse(str);
if(DEBUG) printf("DEBUG num: %s\n",str);

    for(;*str>= '0' && *str <= '9' && (n = 10*n + (*str - '0'))  ; str++)
       printf("%c,%d\n",*str,n) ;
 
   return n;
}

void strindex(char* s, char* t)
{


}

main()
{
    char* str = malloc(100);
    int len = getaline(str,100);
    printf("%d,%s\n",len, str);
    
    reverse(str);

    printf("reverse: %s\n",str);

    int sum = atoi(str);
    printf("atoi: %d\n",sum);
}
