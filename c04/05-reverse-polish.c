/*
 *
 * Reverse Polish calculator
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0	
#define MAXOP	100
#define NUMBER	'0'
#include "06-stack.c"
int getop(char []);
void push(double);
double pop(void);

main()
{

	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF){
if(DEBUG) printf("\nswitch type = %c",type);
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
	    case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else 
				printf("error : zero divisor!\n");
			break;
		case '\n':
			printf("\t%.8g\n",pop());
			break;
		default:
			printf("error: unknown command %s\n ",s);
			break;
		}
	}
	
	return 0;
}
