#include "main.h"

/**
 * _strncat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of bytes to be used from src
 *
 * Return: Pointer to the resulting string
 */
char *_strncat(char *dest, char *src, int n)
{
int dest_len = _strlen(dest);
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[dest_len + i] = src[i];

dest[dest_len + i] = '\0';

return dest;
}
