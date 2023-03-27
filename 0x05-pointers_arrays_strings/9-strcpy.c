#include "main.h"

/**
 *char *_strcpy - Write a function that copies the string pointed to by src
 * @dest
 * @src
 */
char *_strcpy(char *dest, char *src)
{
char *dest_start = dest;
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
return (dest_start);
}
