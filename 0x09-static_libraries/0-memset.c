#include "main.h"

/**
 * _memset - sets a memory area with a specific byte
 * @s: pointer to the memory area to be filled
 * @b: byte to fill the memory area with
 * @n: number of bytes to be filled
 *
 * Return: pointer to the filled memory area @s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;

return (s);
}
