/*
 *
 * To illustrate some of the considerations involved with pointers to and arrays of structures.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getword(char*,int);

struct key{
    char* name;
    int count;
}keyword[] = {
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "continue",0,
    "else",0,
    "for",0,
    "goto",0,
    "if",0,
    "return",0,
    "switch",0,
    "voltile",0,
    "when",0,
    "while",0
};
#define NKEYS   (sizeof(keyword)/sizeof(keyword[0]))

struct key *binsearch(char*, struct key *,int);

main()
{
    char word[MAXWORD];
    struct key *p;
    while(getword(word,MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((p = binsearch(word,keytab,NKEYS)) != NULL)
                p->count++;
    for(p = keytab; p < keytab + NKEYS; p++)
        if(p->count > 0)
            printf("%4d %s\n",p->count,p->name);

    return 0;
}

struct key *binsearch(char *word,struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;
    
    while(low < high){
        mid = low + (high - low)/2;
        if((cond = strcmp(word , mid->name) < 0)
            high = mid;
        else if(cond > 0)
            low = mid + 1;
        else 
            return mid;

    }
    return NULL;
}
