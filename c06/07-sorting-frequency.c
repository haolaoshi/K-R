/*
 * Exercise 6-4
 * Write a program that prints the distinct words int its input 
 * sorted into decreasing order of requency of occurrence.
 * Precede each word by its count.
 */



//[1] sort dec of freq.
//[2] count


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORDS    100
#define BUFFSIZE    100


struct tnode{
    char*   word;
    int     count;
    struct tnode* left;
    struct tndoe* right;
};

int bufp = 0;
char buffer[BUFFSIZE];

int getch()
{
    return bufp > 0 ? buffer[--bufp] : getchar(); 

}

void ungetch(char c)
{
    if(bufp >= BUFFSIZE ) 
        printf("Error !!!  to many characters.\n");
    else
        buffer[bufp++] = c;
}

int getword(char* word,int lim)
{
    int c;
    char* w = word;
    while(isspace(c = getch()));
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }

    for(;--lim > 0; ++w){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

struct tnode* talloc()
{
    return (struct tnode*)malloc(sizeof(struct tnode));
}
struct tnode* addNode(char* word,struct tnode * t)
{
    if(t == NULL){
        t = talloc();
        t->word = strdup(word);
        t->count = 1;
        t->left = t->right = NULL;

    }else if(strcmp(word,t->word) > 0){
        t->right = addNode(word,t->right);
    }else if(strcmp(word,t->word) < 0){
        t->left = addNode(word,t->left);
    }else {
        t->count++;
    }

    return t;
}

void printnode(struct tnode *t)
{
    if(t != NULL){
        printnode(t->left);
        printf("%s,%d\n",t->word,t->count);
        printnode(t->right);
    }   
}

void sortseq(struct tnode *t)
{
    if(t != NULL){
        


    }
}

int main(int argc,char* argv[])
{
    struct tnode* root = NULL;
    char word[MAXWORDS];
    while(getword(word,MAXWORDS) != EOF){
        if(isalpha(word[0]))
            root = addNode(word,root);
    }
    printf("======================\n");
    sortseq(root);
    printnode(root);
    return 0;
}
