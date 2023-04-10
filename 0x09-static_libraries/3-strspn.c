#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: input string
 * @accept: characters to match
 *
 * Return: number of bytes in s which consist of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
unsigned int i, j, count;

count = 0;

for (i = 0; s[i]; i++)
{
for (j = 0; accept[j]; j++)
{
if (s[i] == accept[j])
{
count++;
break;
}
}

if (!accept[j])
break;
}

return (count);
}
