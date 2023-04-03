#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest.
 * @dest: A pointer to the memory area to copy to.
 * @src: A pointer to the memory area to copy from.
 * @n: The number of bytes to copy.
 *
 * Return: A pointer to the beginning of the copied memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;
char *dest_ptr = dest;
char *src_ptr = src;

for (i = 0; i < n; i++)
{
*(dest_ptr + i) = *(src_ptr + i);
}

return (dest);
}
