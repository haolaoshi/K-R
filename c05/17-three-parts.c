/*
 *
 * A sort often consists of three parts 
 *  a comparison that determines the ordering of any pair of object.
 *  an exchange that resverse their order.
 *  a sorting algorithm that makes comparisions and exchanges util the objects are in order.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES    5000
char *lineptr[MAXLINES];

int readlines(char *lineptr, int nlines);
void writelines(char *linptr[],int nlines);
void qsort(void *lineptr[],int left,int right,
            int (*comp)(void *,void *));
int numcmp(char *,char *);

main(int argc, char* argv[])
{
    int nlines;
    int numeric = 0;

    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if((nlines = readlines(lineptr,MAXLINES))>= 0){
        qsort((void **)lineptr,0,nlines - 1,
            (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr,nlines);
        return 0;
    }else{

        printf("input too big to sort\n");
        return 1;
    } 
}
