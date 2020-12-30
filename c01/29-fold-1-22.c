/*
 *
 * Exercise 1-22.
 *
 * Write a program to fold long input lines into two or more shorter lines 
 * after the last non-blank character that occurs before the n-th column 
 * of input .Make sure your program does something intelligent with very long 
 * lines ,and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>

#define NTH_COL 80

main()
{

    int len = 0;

    while((len = getaline()) > 0){
        printf("\n");
    }
    printf("\nExit for len = %d ",len);
}

int getaline()
{
    int c,len;
    len = 0;

    while((c = getchar()) != EOF && c != '\n'){
        printf("%c",c);
        len++;
        if(len == NTH_COL) break;
    }
    return c == EOF ? -1 : len;
}   
