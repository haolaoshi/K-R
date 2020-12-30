/*
 *
 * Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily 
 * long input lines, and as much as possible of the text.
 *
 */


#include <stdio.h>

#define MAXLINE 1000 


int getaline(char line[],int lim){
    int i ,c;
    for(i = 0; i < lim -1 && (((c = getchar()) != EOF) &&( c != '\0'));i++){
        line[i] = c;
    }

    if(c == '\0') line[i++] = '\0';    
     line[i] = '\0';
     printf("\n----%d",i);
     return i;
}

void copy(char from[] ,char to[])
{
  int i = 0 ;
  while( (to[i] = from[i]) != '\0') i++;
}

main()
{
    int len,max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0; len = 0;

    while((len = getaline(line,MAXLINE)) > 0){
       if(len > max){
        max = len; 
        copy(line,longest);
        printf("\n max = %d , %s ",max,longest);
       }
    }
    if(max > 0)  printf("\nLONGEST: %s",longest);
}

