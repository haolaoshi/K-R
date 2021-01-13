/*
 *
 * Example.
 */

#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt,...)
{
    va_list ap;//pointer to each unnamed arg in turn
    char *p,*sval;
    int ival;
    double dval;

    va_start(ap,fmt);//make ap point to 1st arg 
    for( p = fmt; *p; p++){
        if(*p != '%'){
            putchar(*p);
            continue;
        }
        switch(*++p){
        case    'd':
            ival = va_arg(ap,int);
            printf("%d",ival);
            break;
        case    'f':
            dval = va_arg(ap,double);
            printf("%f",dval);
            break;
        case    's':
            for(sval = va_arg(ap,char *); *sval;sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;

        }
    }
    va_end(ap);//clean up when done
}


main()
{
 int a = 100;
 char *b = "abcdefg";
 double c = 3.1415926;
 minprintf("%d,%s,%f\n",a,b,c);

}
