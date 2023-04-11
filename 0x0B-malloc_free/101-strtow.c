#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to be counted.
 *
 * Return: The number of words counted.
 */
int count_words(char *str)
{
int count = 0, in_word = 0;

while (*str)
{
if (*str != ' ')
{
if (!in_word)
in_word = 1, ++count;
}
else
in_word = 0;

++str;
}

return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: If str is NULL or contains no words - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
char **words;
int word_count, i = 0, j, k, len = 0, start;

if (!str || !*str)
return (NULL);

word_count = count_words(str);
if (word_count == 0)
return (NULL);

words = malloc(sizeof(char *) * (word_count + 1));
if (!words)
return (NULL);

while (str[i])
{
if (str[i] == ' ')
{
i++;
continue;
}

start = i;
while (str[i] && str[i] != ' ')
len++, i++;

words[j] = malloc(sizeof(char) * (len + 1));
if (!words[j])
{
for (k = 0; k < j; k++)
free(words[k]);

free(words);
return (NULL);
}

for (k = 0; k < len; k++)
words[j][k] = str[start + k];

words[j][k] = '\0';
j++, len = 0;
}

words[j] = NULL;
return (words);
}
