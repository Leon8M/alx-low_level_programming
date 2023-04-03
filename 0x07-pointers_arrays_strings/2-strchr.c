#include "main.h"
#include <stddef.h>

/**
 * _strchr - Locates a character in a string.
 * @s: A pointer to the string to search.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence of the character c in the string s,
 * or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}

s++;
}

if (*s == c)
{
return (s);
}

return (NULL);
}
