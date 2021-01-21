/*
 *
 * Exercise 4-1.
 *      Write the function strrindex(s,t),wihich returns the postion of the rightmost occurrence of t in s , or -1 if there is none.
 *
 */
#include <stdio.h>
#include <string.h>
#define MAXLEN  1000
#define PATTERN "aa"

int strrindex(char s[],char t[]);
int anotherline(char s[]);

main()
{
    char c;
    int pos= 0;
    char s[MAXLEN];
    int len =0;
    while((len = anotherline(s)) > 0){
       pos = strrindex(s,PATTERN); 
       if(pos > 0){
        printf("\nBingo! %s",s);
       }
       
       printf("\n len = %d, find %s  in %s , pos=%d\n",len,PATTERN,s,pos);
    }
}

int anotherline(char s[])
{
    int c;
    int i =0;
    while((c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
int strrindex(char s[],char t[])
{
    int i,j;
    int z = 0;
    for(i = strlen(s)-1;i>= 0 ; i--){
        z = i;
        j = strlen(t) - 1;
        if(t[j] != s[i]) continue;
        else 
        for(j=strlen(t) - 2,i -= 1; j>=0 && t[j] == s[i] ;i--,j--);
        if(j == 0) return i;
        else i=z;
    }
    return -1;
}
