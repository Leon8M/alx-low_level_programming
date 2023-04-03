#include "main.h"

/**
 * _memset - Fills memory with a constant byte.
 * @s: A pointer to the memory area to fill.
 * @b: The constant byte to fill with.
 * @n: The number of bytes to fill.
 *
 * Return: A pointer to the filled memory area.
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
char *ptr = s;

for (i = 0; i < n; i++)
{
*ptr = b;
ptr++;
}

return (s);
}
