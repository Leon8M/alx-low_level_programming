#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int _atoi(char *s)
{
int sign = 1;
int num = 0;
int i = 0;

while (s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
else if (s[i] >= '0' && s[i] <= '9')
{
if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
return (sign == 1 ? INT_MAX : INT_MIN);
num = num * 10 + (s[i] - '0');
}
else if (num != 0)
break;
i++;
}

return (num *sign);
}
