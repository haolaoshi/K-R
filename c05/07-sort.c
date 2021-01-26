/*
 *
 * Eg,Sorting
 *
 */

#include <stdio.h>
#include <string.h>

#define DEBUG   0
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
void qsort(char *lineptr[],int lef,int right);

main()
{
    int nlines;
    if((nlines = readlines(lineptr,MAXLINES)) >= 0) {
if(DEBUG)    printf("lines : %d \n",nlines);
        qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("error: input too long to sort\n");
        return 1;
    }
}

#define MAX_LEN 1000
int getaline(char *,int);
char *alloc(int);

int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAX_LEN];

    nlines = 0;
    while((len = getaline(line,MAX_LEN)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL )
        return  -1;
    else{
        line[len - 1] = '\0';
        strcpy(p,line);
        lineptr[nlines++] = p;
if(DEBUG)         printf("lines %d , len = %d, %s\n",nlines ,len, p);
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for(i = 0; i < nlines; i++)
        printf("%s\n",lineptr[i]);

}

int getaline(char *line,int max)
{
    char c;
    int i ; 
    for(i= 0; (c = getchar()) != EOF && c != '\n' && i < (max - 1); i++)
        line[i] = c;
        
    if(c != EOF) i++; 

    line[i] = '\0';
    return i;
}

#define ALLOCSIZE   10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n; 
    }else
        return 0;
}
void qsort(char *v[],int left,int right)
{
    int i,last;
    void swap(char *v[],int i,int j);

    if(left >= right)
        return ;

    swap(v,left,(left + right)/2);
    last = left;

    for(i = left + 1; i <= right ; i++)
        if(strcmp(v[i] , v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort(v,left,last);
    qsort(v,last+1,right);
}

void swap(char *v[],int i,int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
