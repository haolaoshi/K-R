/*
 * Exercise 6-2.
 * Write a program that reads a C program and prints in alphabetical order [1]each group[2] of variable names 
 * that are identical[3] in the first 5 characters , 
 * but different somewherer therafter[4].
 * Don't count words within strings[5] and comments[6].
 * Make 6 a parameter that can be set from the command line[7].
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
    
    if( c == '"'){//[5]
        while((c = getch()) != EOF && c != '\n' && c != '"')
            ;
    }

    if( c == '/' && (c = getch()) == '*')//[5]
        while((c = getch()) != EOF && c != '\n' && (!(c == '*' && (c = getch()) == '/')))
            ;
    if(c != EOF){
        *w++ = c;
    }
        
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    

    for(; --max>0;w++){
        if(!isalnum(*w =getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return w[0];
}

void printnode(struct tnode *t)
{
    if(t != NULL){
        printnode(t->left);
//        if(t->count > 1) 
            printf("%12s\t%4d\n",t->word,t->count);
        printnode(t->right);
    }
}

 int main(int argc,char* argv[])
 {
    if(argc > 1)//[7]
        identical = atoi(argv[1]);
    if(identical <= 1)
        return -1;
    char word[MAXWORD];
    char c ;
    while((c = getword(word,MAXWORD)) != EOF){
        if(isalpha(word[0]))
          //  printf("i will add node %s\n",word);
            root = addNode(word,root,identical);
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
   if(t == NULL){
        t= talloc();
        t->word = strdup(word);
        t->count = 1;
        t->left = NULL;
        t->right = NULL;
   }else if(strncmp(t->word,word,identical)> 0){
        t->left = addNode(word,t->left,num);
   }else if(strncmp(t->word,word,identical)<0){
        t->right = addNode(word,t->right,num);
   }else{
        t->count++;
   }
   return t;
}
/*
char *strdup(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    if( p != NULL)
        strcpy(p,s);
    return p;
}
*/

