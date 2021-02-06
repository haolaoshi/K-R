/*
 * Exercise 5-14.
 *  Modify the sort program to handle a -r flag;
 *  which idicates sorting in reverse (decreasing) order.
 *  Bu sure that -r works with -n.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXLINE 1000
#define MAXLEN  1000
#define BUFFSIZE    1000

static char allocbuf[BUFFSIZE];
static char* allocpf = allocbuf; 
char* lineptr[MAXLINE];


char* alloc(int n)
{
    if(allocpf + BUFFSIZE - allocbuf > n ){
        allocpf += n;
        return allocpf - n;
    }else
        return 0;
}

int getaline(char line[], int max)
{
    int c, len;
    len = 0;
    while((c = getchar()) != EOF && c != '\n' && ( len < max - 1)){
        line[len++] = c;
    }
    if(c != EOF) line[len++] = '\0';
    line[len] = '\0';
    return len;
}

void myswap(char* v[],int i,int j)
{
    if(i > j) return ;
    char* p = v[i];
    v[i] = v[j];
    v[j] = p;
}


int numcmp(char* s1,char* s2)
{
    double d1,d2;
    d1 = atof(s1);
    d2 = atof(s2);
    if(d1 < d2 ) return -1;
    else if(d1 > d2 ) return 1;
    else return 0;
}

void writelines(char* lineptr[],int nlines)
{
    int n = 0;
    printf("============================\n");
    for(n = 0; n < nlines; n++)
        printf("%s\n",lineptr[n]);
}
/***Cannot write out ***/
void myqsortr(void *v[],int left, int right, int (*comp)(void *,void *))
{
    int i,last;
    if(left > right ) return ;

printf("reverse version sort!\n");
    myswap(v,left,(left + right)/2);

    last = left;
    for(i= left + 1; i <= right; i++)
        if((*comp)(v[i],v[left])> 0)
            myswap(v,++last,i);
    myswap(v,left,last);
    myqsort(v,left,last - 1,comp);
    myqsort(v,last + 1,right, comp);

}
/***Cannot write out ***/
void myqsort(void *v[],int left, int right, int (*comp)(void *,void *))
{
    int i,last;
    if(left > right ) return ;

    myswap(v,left,(left + right)/2);

    last = left;
    for(i= left + 1; i <= right; i++)
        if((*comp)(v[i],v[left])< 0)
            myswap(v,++last,i);
    myswap(v,left,last);
    myqsort(v,left,last - 1,comp);
    myqsort(v,last + 1,right, comp);

}
/**Cannot Write out****/
int readlines(char* lineptr[],int max)
{
    int nlines,len;
    char* p, line[MAXLEN];
    nlines = 0;
    while((len = getaline(line,MAXLEN)) > 0){
        if( nlines >= MAXLINE || (p = alloc(len)) == 0){
            printf("Error.\n");
            return -1;
        }
        line[len - 1] = '\0';
        strcpy(p , line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

int main(int argc , char* argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;
    if(argc > 1 && strcmp(argv[1] , "-n") == 0)
        numeric = 1;
    else if(argc >1 && (strcmp(argv[1],"-nr") == 0 || strcmp(argv[1],"-rn") == 0 )){
        numeric = 1;
        reverse = 1;
    }else if(argc > 1 && strcmp(argv[1] , "-r") == 0){
        reverse = 1;
    }

printf(" r = %d , n = %d \n",reverse, numeric);

    if((nlines = readlines(lineptr,MAXLINE))>= 0){
        if(reverse) 
            myqsortr((void **)lineptr,0,nlines - 1,(int(*)(void*,void*))(numeric ? numcmp : strcmp));
        else 
            myqsort((void **)lineptr,0,nlines - 1,(int(*)(void*,void*))(numeric ? numcmp : strcmp));

        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("input too long\n");
        return 1;
    }
}
