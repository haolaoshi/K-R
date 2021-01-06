/*
 * Exercise 6-3.
 * Write a cross-referencer that prints a list of all words[1] in a document,
 * and,for each word, a list of the line numbers[2] on which it occurs.
 * Remove noise words like "thie " ,"and" ,and so on[3].
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



//[1] all words, tree node->word;
//[2] line numbers, node->line[];----line has extream;//char *s;?
//[3] the, and ,to , ????


#define MAXWORD     100
#define MAXLINES    100
struct tnode {
    char    *word;
    int     lines[MAXLINES];
    struct tnode    *left;
    struct tnode    *right;
};

char* exwords[]={
    "the",
    "and",
    "a",
    "an",
    "A",
    "The",
    "And",
    "of",
    "are",
    "is",
    "do",
    "with",
    "to",
    "it",
    "or",
    "are"
 };


int linenumber = 0;

void printall(struct tnode *t)
{
    if(t != NULL){
        printall(t->left);
        printf("%s,",t->word);
        int i =0;
            while(t->lines[i]) printf("%d,",t->lines[i++]);
        printf("\n");
        printall(t->right);
    }
}
struct tnode * talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
char* reverse(char *s)
{
    int i,j,k;
    for(i =0 ; j =  strlen(s)- 1,i < j ; i++,j--){
        char c = s[i];
        s[i] = s[j]; 
        s[j] = c;
    }
}

char* itoa(int num,char* p)
{
    int sign;
    if((sign = num) < 0 )
        num = -num;
    int i = 0;

    do{
       p[i++] = num % 10 + '0'; 
    }while(num/= 10 > 0);
    if(sign < 0) 
        p[i++] = '-';
    p[i] = '\0';
    reverse(p);
}



struct tnode * addNode(char* word,struct tnode * t,int linenumber)
{
    if(t == NULL){
        t = talloc();
        t->word = strdup(word);
        t->lines[0] = linenumber;
        t->lines[1] = '\0';
        t->left = t->right = NULL;
        int i =0;
        while(t->lines[i]) printf("Create-lines-> [%d]\n",t->lines[i++]);
    }else if(strcmp(t->word,word)> 0){
        t->left = addNode(word,t->left,linenumber);
    }else if(strcmp(t->word,word)< 0){
        t->right = addNode(word,t->right,linenumber);
    }else{
        int n = 0; 
        while(t->lines[n])
            printf(" [%d],",t->lines[n++]);
        t->lines[n]  = linenumber;
        t->lines[n+1]  = '\0';
    }
    return t;
}
char getword(char* word,int lim)
{
    int c;
    int n;
    char *w = word;
    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;

    if(c == '\n') 
        linenumber++;

   if(!isalpha(c)){
        *w = '\0';
        return c;
   }

    for(;--lim >0; w++)
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;//DO NOT FOREGET! 
        }
    if(*w == '\n')
        linenumber++;
    *w = '\0';

    return word[0];
}

/*if word in extra[i],return false(0),otherwise return true(1);*/
int extra(char *word)
{
    int i = 0;
    for(i = 0; i < sizeof(exwords)/sizeof(exwords[0]); i++)
        if(strcmp(word,exwords[i]) == 0)
            return 0;
    return 1;
}


int main(int argc, char *argv[])
{
    struct tnode *root;
    root = NULL;
    char word[MAXWORD]; 
    while(getword(word,MAXWORD) != EOF){
        if(isalpha(word[0]) && extra(word))
          root = addNode(word,root,linenumber);
    }       
    printf("===========================\n");
    printall(root);
}

#define BUFFSIZE    100
char buffer[BUFFSIZE];
int  bufp = 0;

int getch()
{
    return bufp > 0 ? buffer[--bufp] : getchar();
}

void ungetch(char c)
{
    if(bufp > BUFFSIZE) 
        printf("too many chars!\n");
    else
        buffer[bufp++] = c;
}
