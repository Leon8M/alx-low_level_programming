#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: A pointer to the string to search.
 * @accept: A pointer to the string of characters to search for.
 *
 * Return: The number of bytes in the initial segment of s which consist only of
 * bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int match = 1;

while (*s != '\0' && match == 1)
{
char *a = accept;

while (*a != '\0')
{
if (*s == *a)
{
count++;
break;
}

a++;
}

if (*a == '\0')
{
match = 0;
}

s++;
}

return (count);
}
