#include "main.h"

/**
 * _strncpy - copies n bytes of a string to a buffer
 * @dest: the buffer to copy to
 * @src: the string to copy from
 * @n: the number of bytes to copy
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i = 0;
while (i < n && src[i] != '\0') {
dest[i] = src[i];
i++;
}
while (i < n) {
dest[i] = '\0';
i++;
}
return (dest);
}

