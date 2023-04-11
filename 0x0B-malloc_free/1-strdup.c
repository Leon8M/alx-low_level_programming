#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           containing a copy of the string given as a parameter.
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if it fails
 */
char *_strdup(char *str)
{
char *dup;
int len, i;

if (str == NULL)
return (NULL);

for (len = 0; str[len]; len++)
;

dup = malloc(sizeof(char) * (len + 1));
if (dup == NULL)
return (NULL);

for (i = 0; i <= len; i++)
dup[i] = str[i];

return (dup);
}
