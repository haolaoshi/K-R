/**
 *
 * 60 = 1st,March = non-leap
 * 61 = 1st,March = leap year
 *
 */

#include <stdio.h>


static char daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year,int month, int day)
{
    int i,leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for(i = 1; i< month ; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth,int *pday)
{
    int i,leap;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for(i =1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    printf("%d  %d \n",*pmonth,*pday);
}

main()
{
    int year = 2021;
    int day = 188;
    int month = 2;

    printf("Today year = 2021 month = 7 day = 7 , day of year = %d \n",day_of_year(2021,7,7));
    /*
     * space is necessary 
     */
    int *pmonth = malloc(4); 
    int *pday = malloc(4);
    month_day(2021,188,pmonth,pday);
   printf("This year of 188 yay is %d month %d day\n",*pmonth,*pday);
}
