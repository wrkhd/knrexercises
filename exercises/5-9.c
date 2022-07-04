#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint-gcc.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);
static char daytab[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int main() 
{
    printf("%d\n", day_of_year(1998, 10, 10));
    int a = 0, b = 0;
    int *pmonth = &a, *pday = &b;
    month_day(1998, 283, pmonth, pday);
    printf("%d %d \n", *pmonth, *pday);
    
    return 0;
}

int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    p = daytab[leap];
    while(--month) {
        day += *(++p);
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    char *p;
    p = daytab[leap];
    char count = 0;
    while(yearday > *p) {
        yearday -= *p;
        p++;
        count++;
    }
    *pday = yearday;
    *pmonth = count;
}