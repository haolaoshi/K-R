/*
 *
 *
 * 5.12 Complicated Declarations.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN    100
enum {NAME,PARENS,BRACKETS};

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[100];

/*parse a direct declarator */
void dirdcl(void)
{
    int type;
    if(tokentype == '('){
        dcl();
        if(tokentype != ')')
            printf("error, missing ) \n");
    }else if(tokentype == NAME)
        strcpy(name,token);
    else
        printf("Error: expected name or (dcl) \n");

    while((type = gettoken()) == PARENS || type ==BRACKETS)
        if(type == PARENS)
            strcat(out," founction returning");
        else{
            strcat(out," array");
            strcat(out,token);
            strcat(out,"  of");

        }

}

/*parse a declarator */
void dcl(void)
{

    int ns;
    for(ns =0; gettoken() == '*'; ) // count star 
        ns++;
    dirdcl();

    while(ns-- > 0)
        strcat(out,"  pointer to");

}

main()
{
    while(gettoken() != EOF){
        strcpy(datatype,token);
        out[0] = '\0';
        dcl();
        if(tokentype != '\n')
            printf("syntax error\n");
        printf("%s : %s %s \n",name,out,datatype);
    }
    return 0;
}

int gettoken(void)
{
    int c,getch(void);
    void ungetch(int);
    char *p = token;

    while((c = getch()) == ' ' || c == '\t')
        ;
    if(c == '('){
        if((c = getch()) == ')'){
            strcpy(token,"()");
            return tokentype = PARENS;
        }else{
            ungetch(c);
            return tokentype = '(';
        }
    }else if(c == '['){
        for(*p++ = c;(*p++ = getch()) != ']';)
            ;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }else
        return tokentype = c;

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


