/*
 * binary tree.
 *
 */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct tnode{
    char*   word;
    int     count;
    struct  tnode   *left;
    struct  tnode   *right;
};

struct tnode *addtree(struct tnode *,char *);
void treeprint(struct tnode *);
int getword(char *,int);
int debuginfo = 0;

//if(debuginfo ) printf("DEBUG:   \n");
int main(int argc, char* argv[])
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    
    if( (argc > 1) && (strcmp(argv[1],"-d") == 0) ){
        debuginfo = 1;
    }
    while(getword(word,MAXWORD) != EOF)
        if(isalpha(word[0]))
            root = addtree(root,word);
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
/*
char *strdup(char *s)
{
    char *p;
    p = (char*) malloc(strlen(s) + 1);
    if(p  != NULL)
        strcpy(p,s);
    return p;
}
*/

#define BUFFSIZE    100
int bufferp = 0;
char buffer[BUFFSIZE];

int getch()
{
   return (bufferp > 0 ? buffer[--bufferp] : getchar()); 
}

void ungetch(char c)
{
    if(bufferp >= BUFFSIZE) 
        printf("Too many charactors!");
    else
        buffer[bufferp++] = c;
}

int getword(char *word,int max)
{
    char *w = word;
    int c;

    while(isblank(c = getch()));
    if(c != EOF)
        *w++ = c;
    
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }

    int n ;
//this is the surprisingly code.
    for(;max-- >0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';

    return word[0];
}



struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;
    if(p == NULL){
        p  = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left= p->right = NULL;
if(debuginfo) printf("DEBUG: w = (%s),  p->word = (%s)  \n",w,p->word);
    }else if((cond = strcmp(p->word,w)) == 0)
        p->count++;
    else if(cond < 0)
        p->left = addtree(p->left,w);
    else
        p->right = addtree(p->right,w);
    return p;
}

void treeprint(struct tnode *p)
{
    if(p != NULL){
        treeprint(p->left);
        printf("[%4d] [%s]\n",p->count, p->word);
        treeprint(p->right);
    }

}

struct tnode *talloc(void)
{
    return (struct tnode*) malloc(sizeof(struct tnode));

}


