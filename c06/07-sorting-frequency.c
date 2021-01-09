/*
07-sorting-frequency.c:97:16: warning: assignment from incompatible pointer type [enabled by default]
p->next = freq;
^
07-sorting-frequency.c:98:13: warning: assignment from incompatible pointer type [enabled by default]
freq = p;
^
07-sorting-frequency.c:101:18: error: dereferencing pointer to incomplete type
while(freq->word[i++]);
^
07-sorting-frequency.c:102:12: error: dereferencing pointer to incomplete type
freq->word[i++] = (char*)strdup(w);
^
07-sorting-frequency.c:103:12: error: dereferencing pointer to incomplete type
freq->word[i] = NULL;
                                                                                     *
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

struct tfreq{
    int count;
    char* word[MAXWORDS];
    struct tfreq* next;
};

int bufp = 0;
char buffer[BUFFSIZE];
struct tfreq *froot;

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

struct freq*  addFreq(struct freq* freq, char* w, int c)
{
    
    if(freq == NULL){
        freq = (struct tfreq*)malloc(sizeof(struct tfreq));
        freq->word[0] = strdup(w);
        freq->word[1] = '\0';
        freq->count = c + 1;
        freq->next = NULL;
    }else if(freq->count > (c + 1)) {
        addFreq(w,c,freq->next);
    }else if(freq->count < (c + 1)) {
       struct tfreq* p = NULL; 
       p = (struct tfreq*)malloc(sizeof(struct tfreq));
       p->word[0]  = strdup(w);
       p->count = (c + 1);
       p->next = freq;
       freq = p;
    }else{
       int i =0;
       while(freq->word[i++]); 
       freq->word[i++] = (char*)strdup(w);
       freq->word[i] = NULL;
       //printf("[%s]\n",freq->word);
    }
    return freq;
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
        froot = addFreq(t->word,t->count,froot);
        t->count++;
    }

    return t;
}

void printfreq()
{
    if(froot != NULL){
        while(froot && froot->count > 0){
            printf("[%d]",froot->count);
            int i = 0 ;
            while(froot->word[i]) printf("(%s),",froot->word[i++]);
            printf("\n");
            froot= froot->next;
        }   
    }
}
void printnode(struct tnode* t)
{
    if(t != NULL){
        printnode(t->left);
        printf("%s,%d\n",t->word,t->count);
        printnode(t->right);
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

    printfreq();
//    sortseq(root);
//    printnode(root);
    return 0;
}
