/*
 *
 *
 *
 * Exercise 1-21.
 * Write a program entab
 * that repaces strings of blanks by the minumum number of tabs and blanks
 * to achieve the same spacing.
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 *
 */

#include <stdio.h>

#define TABSPACE    4

int getaline();

main()
{
    int c,len;

    while((len = getaline()) < 0){
        printf("\nExit for EOF \n");
        break;
    }
}

int getaline()
{
    int c,len;
    while( (c = getchar()) != EOF && c != '\n'){
        if( c != ' ') printf("%c",c);
        else if(c == ' ' && len < TABSPACE){
            len++;
            continue;
        }
        else  if(c == ' ' && len == TABSPACE){//current is or not a blank , 
            len = 1;
            printf("\t");
        }else{
            printf("Never go herer!!!");
        }
    }

}
