#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program
 * @ac: the number of arguments
 * @av: an array of pointers to the arguments
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
char *str;
int i, j, k, len;

if (ac == 0 || av == NULL)
return (NULL);

len = 0;
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
len++;
j++;
}
len++;
}

str = malloc((len + 1) * sizeof(char));
if (str == NULL)
return (NULL);

k = 0;
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
str[k] = av[i][j];
j++;
k++;
}
str[k] = '\n';
k++;
}
str[k] = '\0';

return (str);
}
