/*
 * Example 
 * p133
 * The keyword-counting program begins with the definition of keytab.
 * The main routine reads the input by repeatedly calling a function
 * getword that fetches one word at a time.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define DEBUG  0 
#define MAXWORD 100
struct key{
    char *word;
    int count;
} keytab[] = {
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "const",0,
    "continue",0,
    "default",0,
    "if",0,
    "void",0,
    "volatile",0,
    "while",0
};
int getword(char*,int);
int binsearch(char*,struct key *,int);

#define NKEYS  (sizeof keytab / sizeof keytab[0])
main()
{
    int n;
    char word[MAXWORD];
    while(getword(word,MAXWORD) != EOF )
        if(isalpha(word[0])){
            if((n = binsearch(word,keytab,NKEYS)) >= 0){
                keytab[n].count++;
     if(DEBUG)  printf("bingoo! got %s \n",word);
            }else 
     if(DEBUG)  printf("cannot find a %s\n",word);
        }
    for(n =0; n < NKEYS; n++)
        if(keytab[n].count > 0)
            printf("%4d  %s\n",keytab[n].count,keytab[n].word);
        else printf(".");
    return 0;
}

int binsearch(char *word,struct key tab[],int n)
{

if(DEBUG) printf("\tbinsearch [%s],%d===\n",word,n);
    int cond;
    int low ,high,mid;

    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high)/2;
 if(DEBUG)       printf("(%d,%d,%d) strcmp %s  == %s \n",low,mid,high,word,tab[mid].word);
        if((cond = strcmp(word,tab[mid].word)) < 0)
            high = mid - 1;
        else if(cond > 0)
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}
#define BUFFSIZE	100

char buf[BUFFSIZE];
int bufp = 0;

int getch(void)
{

	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFFSIZE)
		printf("ungetch : too many characters.\n");
	else
		buf[bufp++] = c;
}


int getword(char *word,int lim)
{
    int c,getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()))
    ;

    if(c != EOF)
        *w++ = c;
    else
        printf("This is a EOF !\n");

    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for(; --lim>0; w++)
        if(!isalnum(*w= getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
if(DEBUG)    printf("%c\n",word[0]);
    return word[0];
}
