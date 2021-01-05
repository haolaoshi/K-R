/*
 * Exercise 6-2.
 * Write a program that reads a C program and prints in alphabetical order each group of variable names that are identical in the first 5 characters , 
 * but different somewherer therafter.
 * Don't count words within strings and comments.
 * Make 6 a parameter that can be set from the command line.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define MAXWORD 100 
struct tnode{
    char* word;
    int   count;
    struct tnode*  left;
    struct tnode*  right;
};

struct tnode* root;
struct tnode* addNode(char *, struct tnode *, int num);

int identical = 6;

char getword(char* word,int max)
{
    char* w = word;
    int n ;
    int c ;

    while(isspace(c = getch()))
        ;

    if(c != EOF){
        *w++ = c;
    }
    
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }

    for(; max-->0;w++){
        if(!isalnum(c =getch())){
            ungetch(c);
            break;
        }

    }
    *w = '\0';
    return w[0];
}

void printnode(struct tnode *t)
{
    if(t ! = NULL){
        printnode(t->left);
        printf("%s:%d\n",t->word,t->count);
        printnode(t->right);
    }
}

 int main(int argc,char* argv[])
 {
    if(argc > 1)
        identical = atoi(argv[1]);
    if(identical <= 1)
        return -1;
    char* word[MAXWORD];
    while(getword(word,MAXWORD) != EOF){
        if(isalpha(word[0]))
            addNode(word,root,identical);
    }
    printnode(root);
 }

#define BUFFSIZE    1000
char buff[BUFFSIZE];
int bufferp = 0;

int getch()
{
    return  bufferp > 0 ? buff[--bufferp] : getchar();
}

void ungetch(char c)
{
    if(bufferp >= BUFFSIZE)
        printf("too many characters!");
    else
        buff[bufferp++] = c;
}

struct tnode* talloc()
{
    return (struct tnode*) malloc(sizeof(struct tnode));

}

struct tnode* addNode(char *word, struct tnode *t, int num)
{
    char *strdup(char *);

printf("\twill add node %s\n",word);
   if(t == NULL){
        t= talloc();
        t->word = strdup(word);
        t->count = 1;
        t->left = NULL;
        t->right = NULL;
   }else if(strcmp(t->word,word)> 0){
        addNode(word,t->right,num);
   }else if(strcmp(t->word,word)<0){
        addNode(word,t->left,num);
   }else{
        t->count++;
   }
}

char *strdup(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if( p != NULL)
        strcpy(p,s);
    return p;
}


