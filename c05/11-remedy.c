/*
 * Exercise 5-8.
 *  There is no  error check in day_of_year or month_day .
 *  Remedy this defect.
 *  /
 *
 *
 */

#include <stdio.h>

#define     MAXLEN  100

int readline(char* line,int );


static char *daytab[13]= {
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day)
{
    int i,leap;
    if(year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
        return -1;
    
    leap  = year %4 == 0 && year % 100 != 0 || year %400 == 0 ;

    for (i = 1; i <month ; i++)
        day += daytab[leap][i];
    return day;


}
void month_day(int year,int yearday, int *pmonth, int *pday)
{
    int i,leap;
    if(year <= 0 || yearday <=0 || yearday > 366 ) 
        return -1;

    leap  = year %4 == 0 && year % 100 != 0 || year %400 == 0 ;
    for(i = 1; yearday > taytab[leap][i] ; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
