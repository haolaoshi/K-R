/*
 * Exercise 1-20
 * Write a program detab that replaces tabs in the input 
 *
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops,say every n columns.
 * Should be a variable or a symbolic parameter ? 
 */
#include <stdio.h>

#define TABSPACE    4

int getaline();

main()
{
    int c,len;
    len = 0;
    while((len = getaline()) > 0){
       printf("."); 
    }
    if(len == -1) printf("Exit while");
    else printf("Exception occurs.");
}
void printtab(){
    int i = 0;
    while(i++<TABSPACE) printf("_");
}
int getaline()
{
    int c;

    while((c = getchar()) != EOF && c != '\n'){
        if(c == '\t') printtab(); 
        else printf("%c",c);
    }
    return c == EOF ? -1 : 1;
}
