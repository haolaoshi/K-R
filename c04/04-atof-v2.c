/*
 *
 * Exercise 4-2.
 *  Extend atof to handle scientifc notaion of the form
 *      1234.45e-6
 *  where a floating-point number may be followed by e or E and an optionally
 *  signed exponet.
 */


#include <stdio.h>

#include <ctype.h>
//
#define MAX_LINE    100
#define DEBUG   0  

//float   atof(char s[])
double   atof(char s[])
{
    int i=0;
    double v= 0;
    double sign= 1.0;
    int power = 1;
    int v2 = 0;
    double  times = 1.0;
    
    
    for(i=0; isspace(s[i]);i++);
    
    if(s[i] == '-' || s[i] == '+'){
      sign = ( s[i] == '-') ? -1.0 : 1.0;
      i++;
    }

    for(i;isdigit(s[i]);i++)
        v = 10 * v + (s[i] - '0');
if(DEBUG) printf("\na1,value=%g",v);

    if(s[i] == '.'){
        i++;
        for(i;isdigit(s[i]); i++){
            v = 10 * v + (s[i]- '0');
            power *= 10;
        }

    }


if(DEBUG) printf("\nb1,value= %g",v);
    if(s[i+1] == '-' && (s[i] == 'e' || s[i] == 'E')){
        i +=2;
        for(i;isdigit(s[i]); i++){
            v2 = v2 * 10 + (s[i] - '0');
        }
        times = 1;
if(DEBUG) printf("\nb,%g",v2);
        for(i =0 ; i < v2;i++) times /= 10;
if(DEBUG) printf("\nb2,times=%d,value=%g ",times,v);
        return (double)(sign * v/ power  * times);
    }
    else if(s[i] == 'e' || s[i] == 'E'){
if(DEBUG) printf("\nc,E+ bgeing : value=%g",v);
        i++;
        for(i;isdigit(s[i]) ; i++){
            v2 = v2 * 10 + (s[i]-'0');
        }
        times= 1;
if(DEBUG) printf("\nd,v2=%d",v2);
        for(i =0 ; i < v2;i++) times *= 10;
if(DEBUG) printf("\nf,times=%d,value=%g ",times,v);
        return (double)(sign * v/ power  * times);
    }
if(DEBUG) printf("\ne,value=%g",v);
    return (double)(sign) * v / power;
}

int getaline(char s[],int max)
{
    int c, i ;
    i = 0;
    while( (i < max - 1) && (c = getchar()) != EOF && c != '\n'){
        s[i++ ] = c;
    }
    if(c == EOF) return - 1;
    if(c == '\n') s[i] = '\0';
if(DEBUG) printf("\n%s",s);
    return i;
}

main()
{
    char s[MAX_LINE];
    while(getaline(s,MAX_LINE)> 0 ){
        printf("\nResult= %g",atof(s));
    }

    return 0;
}
