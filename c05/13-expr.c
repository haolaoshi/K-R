/*
 * Exercise 5-10.
 * Write the program expr,which evaluates a reverse Posish expression from the command line,
 * where each operator or operand is a separate argument.
 * For example 
 *  expr 2 3 4 + *
 *  eavluates 2 X ( 3 + 4) 
 */

#include <stdio.h>



main(int argc, char *argv[])
{
    int lvalue = 0 , rvalue = 0;
    int *p = malloc(2*4);

    while(--argc > 0)
        if(isdigit(*++argv)){
            *p++ = *++argv; 
        }else{//is alpha
            switch(*++argv){
            case '+':
                lvalue += *p + *--p;
                break;
            case '-':
                rvalue = *p; 
                lvalue += *--p - rvalue; 
                break;
            case '*':
                lvalue += *p * *--p;
                break;
            case '/':
                rvalue = *p;
                lvalue += *p / rvalue;
                break;
            default:
                printf("unhadle errors\n");
                break;
            }
        }
}
