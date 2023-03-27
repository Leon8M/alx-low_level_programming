#include "main.h"

/**
 * _strlen - Computes the length of a string.
 *
 * @s: The string to compute the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
int len = 0;

while (*s++)
len++;

return (len);
}

/**
 * puts_half - Prints the second half of a string.
 *
 * @str: The string to print the second half of.
 */
void puts_half(char *str)
{
int len = _strlen(str);
int i = (len % 2 == 0) ? len / 2 : (len - 1) / 2 + 1;

for (; i < len; i++)
_putchar(str[i]);

_putchar('\n');
}
