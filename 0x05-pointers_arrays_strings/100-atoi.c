#include "main.h"

/**
 * _atoi - Convert a string to an integer
 * @s: Pointer to the string to convert
 *
 * Return: The integer value of the string
 */
int _atoi(char *s)
{
int sign = 1, result = 0;
char c;

while (*s)
{
c = *s++;

if (c >= '0' && c <= '9')
{
if (result > INT_MAX / 10 ||
(result == INT_MAX / 10 && (c - '0') > INT_MAX % 10))
{
result = (sign == 1) ? INT_MAX : INT_MIN;
break;
}

result = result * 10 + (c - '0');
}
else if (c == '-')
{
sign *= -1;
}
}

return result * sign;
}
