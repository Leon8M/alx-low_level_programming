#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @s: Pointer to the string to be modified.
 *
 * Return: Pointer to the modified string.
 */
char *cap_string(char *s)
{
int i;


for (i = 0; s[i] != '\0'; i++)
{
if ((i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n' || s[i - 1] == ',' || s[i - 1] == ';' || s[i - 1] == '.' || s[i - 1] == '!' || s[i - 1] == '?' || s[i - 1] == '"' || s[i - 1] == '(' || s[i - 1] == ')' || s[i - 1] == '{' || s[i - 1] == '}') && (s[i] >= 'a' && s[i] <= 'z'))
{
s[i] -= 32;
}
}

return s;
}
