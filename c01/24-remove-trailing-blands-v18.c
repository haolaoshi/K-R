/*
 *
 * Write a program to remove trailing blanks and tabs from ech line of input, and to delete entirely blank lines.
 *
 *
 */


#include <stdio.h>

int getaline();
main()
{
    int len;
    len = 0;
    while((len = getaline()) &&(len >= 0)){
        printf("\n");
    }
    
    printf("\nExit about len = %d",len);
}

int getaline(){
    int c;
    while(((c = getchar()) != EOF) && (c != '\n')){
        if(c != '\t' && c != ' '){
            printf("%c",c);
        }
    }
    return (c == EOF)? -1: 1;
}
