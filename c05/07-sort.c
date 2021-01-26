/*
 *
 * Eg,Sorting
 *
 */

#include <stdio.h>
#include <string.h>


#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
void qsort(char *lineptr[],int lef,int right);

main()
{
    int nlines;
    if((nlines = readlines(lineptr,MAXLINES)) >= 0) {
        qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("error: input too long to sort\n");
        return 1;
    }
}
