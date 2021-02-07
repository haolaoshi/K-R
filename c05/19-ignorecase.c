/*
 *
 * Exercise 5-15.
 * Add the option -f to fold upper and lower case togetther,
 * so that case distinctions are not made durign sorting;
 * for example , 
 * a and A compare equal.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define ALLOCSIZE   10000
#define MAXLEN      1000
#define MAXLINES    1000
#define DEBUG      1 

static char allocbuf[ALLOCSIZE];
static char* allocpf = allocbuf;


char* lineptr[MAXLINES];

int mycmp(char* s1,char* s2)
{
printf("mycmp %s vs %s \n",s1,s2);
    while(*s1 && *s2){
        char a = *s1;
        char b = *s2;
        if(a <=  'Z' && a >='A') a += 32;
        if(b <= 'Z' && b >= 'A') b += 32;
        if(a > b ) return 1;
        if(a < b ) return -1;
        printf("%s,%s,\n",s1,s2);
        s1++;
        s2++;
    }
    if(!s1) return -1;
    if(!s2) return 1;
    printf("Get Equal!\n");
    return 0;
}
void swap(char* v[],int i,int j)
{
    char* p = v[i];
    v[i] = v[j];
    v[j] = p;
}

void myqsort(char* lineptr[],int left,int right,int (*comp)(void*,void*))
{
    int i = 0; 
    int last = 0;
    if(left > right) 
        return ;

    swap(lineptr,left,(left+right)/2);
    last = left;
if(DEBUG)   printf("\tPI = %d \t\t %s \n",last,lineptr[last]);

    for(i  = left + 1; i <= right; i++)
        if((*comp)(lineptr[last],lineptr[i]) > 0)
            swap(lineptr,i,++last);
        else if((*comp)(lineptr[last],lineptr[i]) == 0)
            swap(lineptr,i,++last);

//here pazzle me
    swap(lineptr,left,last);
    myqsort(lineptr,left,last - 1,comp);
    myqsort(lineptr,last + 1,right,comp);
}

int getaline(char line[], int max)
{
    int c, len = 0;

    while((c = getchar()) != EOF && c != '\n' && len < (max -1))
    {
        line[len++] = c;
    }
    if(c != EOF) line[len++] = '\0'; 
    return len;
}

char* alloc(int n)
{
    if(allocpf + ALLOCSIZE - allocbuf  > n ){
        allocpf += n;        

        return allocpf - n;
    }
    return 0;
}

int getlines(char* lineptr[],int max)
{
    int nlines = 0;
    int len = 0;
    char line[MAXLEN];
    char* p;

    while((len = getaline(line,MAXLEN)) > 0){
        if(nlines > (max - 1) || (p = alloc(len)) == 0){ 
            printf("oops !  save new line wrong!!!");
            return -1;
        }else{
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
if(DEBUG)    printf("nlines = %d \n",nlines);
    return nlines;
}


void writelines(char* lineptr[],int nlines)
{

printf("=================RESULTS============\n");
    int i =0;
    for(i = 0; i < nlines; i++)
        printf("%s\n",lineptr[i]);
}

int main(int argc,char* argv[])
{
    int nlines = 0;
    int len = 0;    
    int ignorecase = 0;
    if(argc > 1 && strcmp(argv[1], "-f") == 0)
       ignorecase = 1; 

    if((nlines = getlines(lineptr,MAXLINES)) > 0){
        myqsort(lineptr,0,nlines - 1,(int(*)(void*,void*))(ignorecase ? mycmp : strcmp));
        writelines(lineptr,nlines);
    }else{
        printf("oops! nlines error\n");
        return -1;
    }


    return 0;
}
