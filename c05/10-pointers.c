/*
 *
 * Exercise 5-9.
 *      Rewrite the routines day_of_year and month_day with ponters instead of indexing.
 */

#include <stdio.h>

static char daytab[][13] = {
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year (int year, int month , int day)
{
    int i, leap;

    char *dt;

    leap = year % 4 == 0 && year % 100 != 0 && year % 400 == 0;
    if(leap) dt = daytab[1];
    else dt = daytab[0];

    for(i= 0; i < month; i++) 
        day += *(dt + i);
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i,leap;
    char *p;

    leap = year % 400 == 0 && year % 4 ==0 && year % 100 != 0;
    if(leap) p = daytab[1];
    else p = daytab[0];

    
    for(i = 1; yearday > *(p + i ); i++)
        yearday -= *(p + i);
    *pmonth = i;
    *pday = yearday;
}


main()
{
    printf("2021-7-7 yearday is %d\n",day_of_year(2021,7,7));

    int *pmonth = malloc(4);
    int *pday = malloc(4);
    month_day(2021,188,pmonth,pday);
    printf("2021 's 188 day is %d month %d day \n",*pmonth,*pday);

}
