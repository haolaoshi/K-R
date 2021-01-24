/*
 * Example. Reverse Polish calculator
 * Exercise 4-3. Given the basic framework , it's straightforward to extend the
 * 		calculator. Add the modulus (%) operator and provisions for negative numbers.
 * Exercise 4-4. Add commands to print the top element of the stack without popping,
 * 		to duplicate it,and to swap the top two elements. 
 * 		Add a command to clear the stack.
 * Exercise 4-5. Add access to library function like sin,exp,and pow.
 * 		See <math.> in Appendix B,Section 4.
 * Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six 
 * 		variables with signle-letters 
 * Exercise 4-7. Write a routine ungets(s) taht will push back an entire stirng onto 
 * 		the input. Should ungets know about buf and bufp,or should it just use ungetch?
 * Exercise 4-8. Suppose that there will never be more than one character of pushback. 
 * 		Modify getch and ungetch accodingly.
 * Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
 * 		what their properties ought to be if an EOF is pushed back,than implement.
 *
 * Exercise 4-10. An alternate organization use getline to read an entire input line.
 * 		this makes getch and ungetch unnecessary.Revise the calculator to use this appro
 * 		ach.
 */

#include <stdio.h>
#include <stdlib.h>
#define DEBUG   0	
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
	int a,b ;	
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
		case '%':
			a = pop();
			b = pop();
			push(b  % a);
			break;
		case '\n':
			printf("\t%.8g\n",pop());
			break;
		case 's':
			show();
			break;
		case 'c':
			clear();
			break;
		default:
			printf("error: unknown command %s\n ",s);
			break;
		}
	}
	
	return 0;
}
