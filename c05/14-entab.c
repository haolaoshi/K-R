/*
 * Exercise 5-11.
 *      Modify the programs entab and detab (written as exercises in chapter 1)
 *      to accept a list of tab stops as arguments
 *      Use the default tab settings if there are no argu.
 *
 *    entab :   +&    replace TABSPACE space to & 
 *    detab :   -@    replace tab to @
 */


#include <stdio.h>
#define MAXLEN  100
#define TABSPACE 4
static char defaultTab = '\t';
main(int argc, char* argv[])
{

int len = 0;
char line[MAXLEN];
int entab = 1;

//argv++;
printf("%i , %s\n",argc , argv[1]);

if(argc > 1 && *argv){
    if(*argv[1] == '-') entab = 0;
    defaultTab = *argv[1];
}
while( getaline(line,MAXLEN,entab) > 0 )
    printf("%s\n",line);

}


int getaline(char line[], int max,int entab)
{
    int len , c;

    len = 0;
    int tb = 0; 
    while(entab && (len < max - 1) && (c = getchar())!= EOF && c != '\n'){
       if(c == ' ') tb++; 
       if(c == ' ' && tb++ < TABSPACE){
            len++;
            continue;
       }
       else if(c == ' ' && tb == TABSPACE){
            c = defaultTab;
       }
       else if(tb > 0)  {
           for(tb; tb >=0 ; tb--) line[len++] = ' '; 
           continue;
       }
       else{
            line[len] = c; 
            len++;
       }
    }
    while(!entab && (len < max - 1) && (c = getchar()) != EOF && c != '\n'){

        if(c == '\t') 
            line[len] = defaultTab;
        else 
            line[len] = c;

    }   
    line[len] = '\0';
    return len;
}
