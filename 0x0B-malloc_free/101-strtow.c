#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * count_words - Count the number of words in a string
 * @str: The input string
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
int i, count = 0, len = strlen(str);

for (i = 0; i < len; i++)
{
if (*(str + i) != ' ' && (*(str + i - 1) == ' ' || i == 0))
count++;
}

return (count);
}

/**
 * allocate_words - Allocate memory for the words array
 * @str: The input string
 * @len: The length of the words array
 *
 * Return: The words array
 */
char **allocate_words(char *str, int len)
{
int i;
char **words;

words = malloc(sizeof(char *) * (len + 1));
if (words == NULL)
return (NULL);

for (i = 0; i < len; i++)
{
*(words + i) = malloc(sizeof(char) * (strlen(str) + 1));
if (*(words + i) == NULL)
return (NULL);
}

return (words);
}

/**
 * strtow - Split a string into words
 * @str: The input string
 *
 * Return: The words array
 */
char **strtow(char *str)
{
int i, j, k = 0, len = 0, count = 0;
char **words;

if (str == NULL || *str == '\0')
return (NULL);

len = count_words(str);
words = allocate_words(str, len);
if (words == NULL)
return (NULL);

for (i = 0; i < strlen(str); i++)
{
if (*(str + i) != ' ' && (*(str + i - 1) == ' ' || i == 0))
{
for (j = i; *(str + j) != ' ' && *(str + j) != '\0'; j++)
count++;
strncpy(*(words + k), (str + i), count);
*(*(words + k) + count) = '\0';
k++;
i = j;
count = 0;
}
}

*(words + k) = NULL;

return (words);
}
