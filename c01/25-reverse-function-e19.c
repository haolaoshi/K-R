/*
 *
 * Exercise 1-19.
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */


#include <stdio.h>
#define MAXLEN  1000

void reverse(char s[], int len);
int getaline(char s[],int maxlen);

main()
{
    char lines[MAXLEN];
    int len = 0;
    while(( len = getaline(lines,MAXLEN))  > 0){
        reverse(lines,len);
        printf("REVERSE: %s\n",lines);
    }
}

int getaline(char lines[],int maxlen){
    int c,len;
    len = 0;
    while(len < (maxlen -1) && (c = getchar()) != EOF && c != '\n'){
       lines[len++] = c; 
    } 
    lines[len] = '\0';
    return (c == EOF) ? -1 : len;
}

void reverse(char s[], int len){
    int i = 0;
    int c;
    for(i; i< (len/2) ; i++){
        c = s[len - i - 1];
        s[len-i-1] = s[i];
        s[i] = c;
    }
}
