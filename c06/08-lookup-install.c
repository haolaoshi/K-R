/*
 *
 * Example.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct nlist{
    struct nlist    *next;
    char    *name;
    char    *defn;
};

#define HASHSIZE    101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;
    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 *hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist    *np;
    for(np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s,np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if((np = lookup(name)) == NULL ){
        np = (struct nlist *)malloc(sizeof(*np));
        if(np == NULL || (np->name = strdup(name)) == NULL){
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else{
        free((void*)np->defn);
    }
    if((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

#define MAXWORDS    100

int main(int argc,char *argv[])
{
    struct nlist *p = install("App","Asia Puper & Paper");
    p = install("Apple","Discover the inovation of the world");
    p = install("Arg","An Alternate reality game");


    p = lookup("Arg");
    if(p != NULL)  
        printf("Arg is : %s \n",p->defn);
    p = lookup("App");
    if(p != NULL) 
        printf("App is : %s \n",p->defn);
    p = lookup("cctv");
    if(p != NULL)
        printf("CCTV is : %s\n",p->defn);
}


