/*
 *
 * 4.2 Function returning Non-Integers
 *
 */

#include <stdio.h>
#include <ctype.h>
#define MAX_LINE    100
#define DEBUG       0
double atof(char s[])
{
    double val,power;
    int i,sign;

    for(i =0 ;isspace(s[i]); i++)
        ;//skip white space 

    sign = (s[i] == '-') ? -1:1; 

    if(s[i] == '+' || s[i] == '-')
        i++;

    for(val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if(s[i] == '.')
        i++;
    /* fraction part is added subsequenctly,by power decide at last */  
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    } 

#if (DEBUG)
    printf("\n%g,%g, %g\n",sign*val,power, val/power);
#endif 
    return sign * val / power;

}


int getaline(char s[],int max)
{
    char c;
    int i =0; 
    while((i < max - 1) && (c = getchar()) != EOF && c != '\n'){
       s[i++] = c; 
       
    }
    if(c == EOF) return -1;
    if(c == '\n') s[i] = '\0';
if(DEBUG)    printf("\n%s",s);
    return i;
}


main()
{
    double sum,atof(char []);//whathell this ?? 
    char line[MAX_LINE];

    sum = 0;
    while(getaline(line, MAX_LINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
