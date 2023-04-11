#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int count_words(char *str);
int get_word_length(char *str);

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL if fails
 */
char **strtow(char *str)
{
char **words;
int i, j, k, len, count;

if (str == NULL || *str == '\0')
return (NULL);

count = count_words(str);
if (count == 0)
return (NULL);

words = malloc(sizeof(char *) * (count + 1));
if (words == NULL)
return (NULL);

for (i = 0, k = 0; i < count; i++)
{
len = get_word_length(str + k);
words[i] = malloc(sizeof(char) * (len + 1));
if (words[i] == NULL)
{
for (j = 0; j < i; j++)
free(words[j]);
free(words);
return (NULL);
}

for (j = 0; j < len; j++)
words[i][j] = str[k + j];
words[i][j] = '\0';

k += len;
while (str[k] == ' ')
k++;
}

words[i] = NULL;

return (words);
}

/**
 * count_words - Counts the number of words in a string
 * @str: The string to count the words
 *
 * Return: The number of words in the string
 */
int count_words(char *str)
{
int count = 0;

while (*str != '\0')
{
if (*str != ' ')
count++;
while (*str != ' ' && *str != '\0')
str++;
if (*str != '\0')
str++;
}

return (count);
}

/**
 * get_word_length - Gets the length of a word in a string
 * @str: The string to get the word length
 *
 * Return: The length of the word
 */
int get_word_length(char *str)
{
int len = 0;

while (str[len] != ' ' && str[len] != '\0')
len++;

return (len);
}
