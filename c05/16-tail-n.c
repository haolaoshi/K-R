/*
 * Exercise 5-13.
 * Write the program tail, which prints the last n lines of its input,
 * By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that tail -n 
 * prints the last n lines.
 * The program should behave rationally no matter how unreasonable
 * the input or the value of n .
 * Write the program so it makes the best use of available storage;lines should be stored as in the sorting prgram of section 5.6
 * not in a two-dimensional array of fixed size.
 */

#include <stdio.h>

#define MAXLINE 1000

char  *lineptr[MAXLINE];
int n = 10;

int main(int argc,char *argv[])
{
     
    if(argc > 1 && atoi(argv[1]) > 10) 
        n = atoi(*argv);
    int len = 0;
    char aline[MAXLINE];
    int i = 0;
    
    while( (len = getaline(aline,MAXLINE)) > 0){
       lineptr[i++] = aline; 
    //   printf("seq:%d - string: %s - len: %d\n",(i-1),lineptr[i-1],len);
    }
    printf("---- i = %d \n",i);
    for(i--; i >0 ;i-- )
        //printf("\t%s\n",lineptr[i--]);
        printf("\t%d--%s\n",i,lineptr[i]);
        
    printf("\nDone.!");
}

int getaline(char line[],int max)
{
    int c = 0;
    int size = 0;
    while((c = getchar()) != EOF && c != '\n'){
        line[size++]  = c ;
    }
    line[size]  = '\0';
    return size;
}

