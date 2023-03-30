#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 *
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *str)
{
int i, j;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; in[j] != '\0'; j++)
{
if (str[i] == in[j])
{
str[i] = out[j];
break;
}
}
}

return (str);
}
