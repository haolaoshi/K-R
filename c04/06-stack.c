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
int slash = 10;
int getop(char s[])
{
	int i,c;
	
if(DEBUG) while(--slash > 0) printf("-");
printf("\n");

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;

	
	if(!isdigit(c) && c != '.' && c != '-' && c != '+'){
		s[1] = '\0';
if(DEBUG) printf("\n\t operators but not +/- %c",c);
		return c;   //not a number
	}
	if(c == '-' || c == '+'){
		if(!isdigit(s[++i] = c = getch())){
			s[1] = '\0';
if(DEBUG) printf("\n\t2 operators is + or -  %c",c);
			return s[0];	
		} 
if(DEBUG)	printf("\n\t FOUND A NEGATIVE NUMBER...%c",s[i]);
	}

//	i = 0;
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
if(DEBUG) printf("\n\t Number or Negative is %s, i = %d",s,i);
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
if(DEBUG)	printf("\n\tFinally, get op is Number %s,i=%d",s,i);
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


