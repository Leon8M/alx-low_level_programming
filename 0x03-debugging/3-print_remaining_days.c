#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int i, days_left = 0;

if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
{
days_in_month[2] = 29;
}

if (month >= 2)
{
for (i = 1; i < month; i++)
{
days_left += days_in_month[i];
}

days_left += day;

if (days_in_month[2] == 29 && month > 2)
{
days_left--;
}
}
else
{
days_left = day;
}

printf("Day of the year: %d\n", days_left);

if (days_in_month[2] == 29 && month == 2 && day == 29)
{
printf("Remaining days: %d\n", 366 - days_left);
}
else
{
printf("Remaining days: %d\n", 365 - days_left);
}
}
