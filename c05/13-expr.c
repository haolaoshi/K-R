/*
 * Exercise 5-10.
 * Write the program expr,which evaluates a reverse Posish expression from the command line,
 * where each operator or operand is a separate argument.
 * For example 
 *  expr 2 3 4 + *
 *  eavluates 2 X ( 3 + 4) 
 */

#include <stdio.h>


//2 3 4 + *
main(int argc, char *argv[])
{
    int lvalue = 0 , rvalue = 0;
    int *p = malloc(4*10);
    memset(p,0,40);
    char c ; 
    printf("%lx, argc = %d\n",p,argc);
    
    int i = 0; 
    for(i = 0; argv[i] != NULL && i < argc ; i++) printf("\n%s",argv[i]);
        while(argv != NULL  && *argv != NULL ){
            i = 0;
           ++argv;
            while(*argv[i]  == ' ') i++; 
            c = *argv[i];

            
            printf("\n");
            switch(c){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
               lvalue = c - '0';
               *p = lvalue;
               p++;
               printf("%lx,data:%d , ",p,lvalue);
               break;
            case '+':
                lvalue = *--p;
                rvalue = *--p;
                rvalue = lvalue + rvalue;
                printf("%lx,add:  = %d\n",p, rvalue );
                *p++ = rvalue;
                break;
            case '-':
                rvalue = *--p; 
                lvalue = *--p; 
                *p++ = lvalue - rvalue;
                break;
            case '*':
                rvalue = *--p;
                *p++ = *--p * rvalue;
                printf("multi = %d\n",*p);
                break;
            case '/':
                rvalue = *--p;
                *p++ = *--p / rvalue;
                break;
            default:
                printf("%lx,sum = %d \n",p,*--p);
                
                break;
            }
      }
      if(*--p) printf("total = %d \n",*p);
}
