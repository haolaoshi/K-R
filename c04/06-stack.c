/*
 *
 *
 *
 * Stack 
 *
 */

#include <ctype.h>
#define MAXVAL 100

int sp= 0;
double val[MAXVAL];


void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error : stack full , can't push %g \n",f);	
if(DEBUG)	printf("\n push a %g,sp = %d",f,sp);
}

double pop(void)
{
if(DEBUG)	printf("\n pop a %g,sp = %d",val[sp-1],sp);
	if(sp > 0)
		return val[--sp];
	else
		printf("pop Error: stack empty.");
	return 0.0;
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i,c;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.'){
if(DEBUG) printf("\n\tget op is not a number %c",c);
		return c;   //not a number
	}
	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	printf("\n\tget op is Number %s",s);
	return NUMBER;
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
