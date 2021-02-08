/*
 *
 * Exercise 5-16.
 * Add the -d (directory order option, which makes comparisons only 
 * on letters, numbers and blanks.
 * Make sure it works in conjunction with -f.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAXLEN  1000
#define MAXLINES    1000
#define ALLOCSIZE   10000
#define SALARY  ('a'-'A')
char* lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];
static char* allocbup = allocbuf;

int directory = 0;
int ignorecase = 0;

void swap(char* v[],int i,int j)
{
    char* p;

    p = v[i];
    v[i] = v[j];
    v[j] = p;
}

int directcmp(char* s1,char* s2)
{
    while(*s1 && *s2){
        char c = *s1;
        char d = *s2;
        if(directory && !( isdigit(c) || isalpha(c) || c == 32) ){
            printf("except c = %s \n",c);
            goto excep; 
        }
        
        if(directory && !( isdigit(d) || isalpha(d) || d == 32)){
            printf("except d = %s \n", d);
            goto excep;
        }
        if(ignorecase){
            if(c >= 'A' && c <= 'Z') c += 32;
            if(d >= 'A' && d <= 'Z') d += 32;
            printf("c=%c,d=%c\n",c,d);
        }
        printf("%s,%s,\n",s1,s2);
        if(c > d) {
            printf("\tAbove\n");
            return 1;
        }
        else if(c < d){
            printf("\tBellow\n"); 
            return -1;
       } 
       s1++;
       s2++;
    }
    if(!s1 && !s2)
        printf("\t\tSuprise ????\n");
    if(!s1) return -1;
    if(!s2) return 1;
    printf("\tGot a Equal!!\n");
    return 0;
excep:
   printf("illegal data!!!\n");
}

void myqsort(char* v[],int left,int right,int (*comp)(void*,void*))
{
    int last = 0;
    int i =0;

    if(left > right) return;

    swap(v,left,(left + right)/2);
    last = left;

    for(i = left + 1; i <= right; i++ )
        if((*comp)(v[i],v[left]) > 0)
            swap(v,i,++last);
        else if((*comp)(v[i],v[left]) == 0 )
            swap(v,i,++last);

    swap(v,left,last);
    myqsort(v,left , last- 1,comp);
    myqsort(v,last+1,right,comp);
}


int alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocbup > n ){
        allocbup += n;
        return allocbup - n;

    }else
        return 0;
}

int getaline(char line[],int max)
{
    int c;
    int len = 0 ;

    while((c = getchar()) != EOF && c != '\n' && (len < (max -1))){
        line[len++] = c;
    }
    if(c != EOF) line[len++] = '\0';
    return len;
}

int getlines(char* lineptr[],int max)
{
    char line[MAXLEN];
    int nlines = 0;
    int len = 0; 
    char* p;

    while((len = getaline(line,MAXLEN)) > 0){

        if(nlines > (max -1) || (p = alloc(len)) == 0){
            printf("Alloc Error!!!\n");
            return -1;
        }else{
            line[len-1] = '\0';
            strcpy(p,line);
            lineptr[nlines++] = p ;
        }
    }
    return nlines;
}

void writelines(char* v[],int nlines)
{
    int i = 0; 
    printf("================output=============\n");
    for(i = 0; i < nlines; i++)
        printf("%s\n",v[i]);
}

int main(int argc, char* argv[])
{

    int nlines;
    
    if(argc >1 && strcmp(argv[1] , "-d") == 0)
        directory = 1;
    if(argc >1 &&( strcmp(argv[1] ,"-fd") == 0 || strcmp(argv[1],"-df") == 0)){
        directory = 1;
        ignorecase = 1;
    }

printf("d = %d, i = %d;  judge = %d \n",directory , ignorecase, (directory + ignorecase) );

    if((nlines = getlines(lineptr,MAXLINES)) > 0){
printf("Get lines  = %d\n",nlines);

        myqsort(lineptr,0,nlines -1, (int(*)(void*,void*))((directory+ignorecase)> 0  ? directcmp : strcmp ));
        writelines(lineptr,nlines);

    }
}
