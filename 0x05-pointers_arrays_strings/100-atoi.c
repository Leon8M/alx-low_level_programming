#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: string to convert.
 *
 * Return: integer value of the string, or 0 if no number found.
 */
int _atoi(char *s)
{
int num = 0;
int sign = 1;
int started = 0;

while (*s)
{
if (*s == '-' && !started)
sign *= -1;
else if (*s == '+' && !started)
sign *= 1;
else if (*s >= '0' && *s <= '9')
{
started = 1;
num *= 10;
num += *s - '0';
}
else if (started)
break;

s++;
}

return num * sign;
}
