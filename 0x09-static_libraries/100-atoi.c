#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: String to be converted
 *
 * Return: The integer value of the converted string
 */
int _atoi(char *s)
{
int sign = 1;
int res = 0;
int i = 0;

if (s[0] == '-')
{
sign = -1;
i++;
}

for (; s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
res = res * 10 + s[i] - '0';
else
break;
}

return (sign * res);
}
