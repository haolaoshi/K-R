/*
 *
 * Extern variable 
 *
 */


#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getaline(void);
void copy(void);


main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while(( len = getaline()) > 0)
    {
    //    printf("\n len = %d, max = %d ",len,max);

        if(len > max){
            max = len;
            copy();
        }

    }
    if(max > 0) 
        printf("%s",longest);

    return 0;
}

int getaline()
{

    int c, i;
    extern char line[];
    for( i=0 ; (i< (MAXLINE - 1)) && ((c = getchar()) != EOF) && (c != '\n') ; ++i)
    {
        line[i] = c;
     }
   //  printf("\ngetaline: %d ",i);
    if(c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
   // printf("------%d\n",i);
    return i;
}
void copy(void)
{
    int i ;
    extern char line[],longest[];

    i = 0;
    while((longest[i] = line[i]) != '\0') ++i;
}
