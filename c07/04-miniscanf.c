/*
 *
 * Exercise 7-4
 * Write a private version of scanf analogous to miniprintf 
 * from the previous section.
 */


#include <stdio.h>
#include <stdarg.h>


main()
{
    int a;
    float b;
    char s[20];
    
    printf("Please in put a number.\n");
    miniscanf("%i",&a);
    printf("\t[%d]\n",a);
    printf("Please in put a double.\n");
    miniscanf("%f",&b);
    printf("\t[%f]\n",b);
    printf("Please in put a string.\n");
    miniscanf("%s",s);
    printf("\t%s\n",s);
}


#define MAXWORD 100
int i = 0; 
void miniscanf(char *fmt,...)
{
    va_list ap;
    char *p, *sval;

    int *ival;
    float *dval;
    char localfmt[MAXWORD];
    
    va_start(ap,fmt);
    for(p = fmt; *p; p++){
        if(*p != '%'){
            localfmt[i++] = *p;
            continue;
         }
         localfmt[i++] = '%';
        while(*(p+1) && !isalpha(*(p+1))){
            localfmt[i++] = *++p; 
        }

        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';

        switch(*++p){
        case    'd':
            ival = va_arg(ap,int*);
            scanf(localfmt,ival);
            //printf("%d",dval);
            break;
        case    'f':
            dval = va_arg(ap,float*);
            scanf(localfmt,dval);
            //printf("%f",dval);
            break;
        case    's':
            sval = va_arg(ap,char *);
            scanf(localfmt,sval);
               // putchar(*sval);
            break;
        default:
            scanf(localfmt);
            break;
        }
        i = 0;
    }
    va_end(ap);
}
