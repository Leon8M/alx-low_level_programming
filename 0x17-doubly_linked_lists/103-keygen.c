#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * generate_key - Generates a key based on the username
 * @username: The username to generate the key for
 */
void generate_key(const char *username)
{
int length = strlen(username);
char *key = malloc((length + 1) * sizeof(char));

if (key == NULL)
{
printf("Memory allocation failed\n");
return;
}

int i;
for (i = 0; i < length; i++)
{
key[i] = username[i] ^ 0x0F;
}

key[length] = '\0';

printf("Generated key for %s: %s\n", username, key);

free(key);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
char *username;

if (argc != 2)
{
printf("Usage: %s username\n", argv[0]);
return (1);
}

username = argv[1];
generate_key(username);

return (0);
}
