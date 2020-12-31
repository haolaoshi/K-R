/*
 * Exercise 2-1:
 *
 * Write a program to determine the ranges of char,short,int, and long 
 * variables, both signed and unsigned , by printing appropriate 
 * values from standard headers and by direct computation.
 * Harder if you compute them:
 * determine the ranges of the various floating-point types.
 *
 */

#include <stdio.h>
#include <math.h>
int compute_char(void);
int compute_int(void);
int compute_long(void);
int compute_double(void);

main()
{

    printf("char c size = %d, max = %d\n", sizeof(char), (int)pow(2,sizeof(char) * 8));
    printf("unsigned char size = %d,max = %d\n",sizeof(unsigned char),(int)pow(2,sizeof(unsigned char) * 8));

    printf("short size = %d,max = %d\n",sizeof(short),(int)pow(2,sizeof(short) * 8));

    printf("int size = %d, max = %d \n",sizeof(int),(int)pow(2,sizeof(int) * 8));
    printf("unsinged int size = %d, max = %d \n",sizeof(unsigned int),(int)pow(2,sizeof(unsigned int) * 8));
    printf("signed int size = %d,max = d \n",sizeof(signed int),(int)pow(2,sizeof(signed int) * 8 ));

    printf("long int size = %d, max = %f \n",sizeof(long),(double)pow(2,sizeof(long) * 8));

    printf("float size = %d, max = %d \n",sizeof(float),(float)(sizeof(float) * 8));
    printf("double size = %d , max = %d \n", sizeof(double),(double)(sizeof(double) * 8 ));
    printf("long double size = %d, max = %d \n", sizeof(long double) ,(double)(sizeof(long double) * 8 ));
    printf("\n Computed range of char : %d \n",compute_char());
    printf("\n Computed range of int : %d \n",compute_int());
    printf("\n Computed range of long : %d \n",compute_long());
    printf("\n Computed range of double : %d \n",compute_double());
}

int compute_char(void)
{
    char x = 1;
    int i = 0;
    while(x)
    {
        x = x << 1; //shift left by 1 bit
        ++i;
    }
    return (i / 8); // transform bits in bytes
}

int compute_int(void)
{
    int x = 1;
    int i = 0;
    while(x)
    {
        x = x << 1; //shift left by 1 bit
        ++i;
    }
    return (i / 8); // transform bits in bytes
}
int compute_long(void)
{
    long x = 1;
    int i = 0;
    while(x)
    {
        x = x << 1; //shift left by 1 bit
        ++i;
    }
    return (i / 8); // transform bits in bytes
}

int compute_double(void)
{
    double x = 1;
    int i = 0;
    while(x)
    {
        x = x << 1; //shift left by 1 bit
        ++i;
    }
    return (i / 8); // transform bits in bytes
}
