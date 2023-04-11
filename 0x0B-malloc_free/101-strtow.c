#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL if fails
 */
char **strtow(char *str)
{
char **array;
int i, j, k, count = 0, len;

if (str == NULL || *str == '\0')
return (NULL);

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
count++;
}

arr = malloc((count + 1) * sizeof(char *));
if (arr == NULL)
return (NULL);

for (i = 0, j = 0; j < count; j++)
{
while (str[i] == ' ')
i++;
len = 0;
while (str[i + len] != ' ' && str[i + len] != '\0')
len++;
arr[j] = malloc((len + 1) * sizeof(char));
if (arr[j] == NULL)
{
for (k = 0; k < j; k++)
free(arr[k]);
free(arr);
return (NULL);
}
strncpy(arr[j], &str[i], len);
arr[j][len] = '\0';
i += len;
}

arr[count] = NULL;

return (arr);
}
