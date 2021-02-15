/*
 * Exercise 6-1:
 * Our version of getword does not properly handle underscores,
 * string constants,
 * comments,
 * or preprocessor control lines.
 * Write a better version.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define MAXLINES    100

struct key{
    char* name;
    int   count;
}keytab[] = {
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "const",0,
    "continue",0,
    "default",0,
    "do",0,
    "else",0,
    "for",0,
    "if",0,
    "goto",0,
    "return",0,
    "switch",0,
    "void",0,
    "votile",0,
    "when",0,
    "while",0
};
#define NKEYS   (sizeof(keytab)/sizeof(keytab[0]))

//struct  key keytab[NKEYS];

int getword(char*,int);
int binsearch(char*,struct key *,int);

int main(int argc, char *argv[])
{
    int n = 0;
    char* word;
    while(getword(word,MAXLINES) != EOF){
        if(isalpha(word[0]))
            if( (n = binsearch(word,keytab,NKEYS))>= 0)
                keytab[n].count++;
    }
    for( n = 0; n < NKEYS; n++)
        if(keytab[n].count > 0)
            printf("%4d %s\n",keytab[n].count,keytab[n].name);

    return 0;
}

int binsearch(char* word,struct key tab[], int num)
{
    int low = 0; 
    int high = num - 1;
    int condition = 0;
    while(low <= high){
        int mid = (low + high)/2;
        if((condition = strcmp(word,tab[mid].name)) > 0){
            low = mid + 1;
        }else if(condition < 0) {
            high = mid - 1;
        }else{
            return mid;
        }
    }
    return -1;
}


#define BUFFSIZE    100
char buf[BUFFSIZE];
int bufferp = 0;


int getch()
{
    return (bufferp > 0) ? buf[--bufferp] : getchar();
}

void ungetch(int c)
{
    if(bufferp >= BUFFSIZE) 
        printf("Error!!!too many chars\n");
    else
        buf[bufferp++] = c;
}

int getword(char *word,int max)
{
    char*  w = word;
    void ungetch(int );
    int c = 0;

    while(isblank(c = getch()))
        ;

    if(c != EOF)
        *w++ = c;

    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for( ; --max > 0;w++)
        if(!isalnum(*w = getch())){
            ungetch(*w);
            printf("%s\n",w);
            break;
        }
    *w = '\0';
    return word[0];
}

