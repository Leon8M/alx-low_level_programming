#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @s: Pointer to the string to be encoded.
 *
 * Return: Pointer to the encoded string.
 */
char *leet(char *s)
{
int i, j;
char *letters = "aeotl";
char *nums = "43071";


for (i = 0; s[i] != '\0'; i++)
{
for (j = 0; letters[j] != '\0' && nums[j] != '\0'; j++)
{
if (s[i] == letters[j] || s[i] == letters[j] - 32)
{
s[i] = nums[j];
}
}
}

return (s);
}
