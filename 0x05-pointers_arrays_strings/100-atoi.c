#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to string to be converted
 *
 * Return: Converted integer value
 */
int _atoi(char *s)
{
int sign = 1;
int result = 0;

while (*s != '\0')
{
if (*s == '-')
{
sign = sign * -1;
}
if (*s >= '0' && *s <= '9')
{
result = result * 10 + (*s - '0');
}
if (*s == '+' || (*s >= '0' && *s <= '9'))
{
break;
}
s++;
}
return (result * sign);
}
