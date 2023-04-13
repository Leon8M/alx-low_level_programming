#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
return (c >= '0' && c <= '9');
}

/**
 * print_error - prints an error message and exits with a status of 98
 */
void print_error(void)
{
printf("Error\n");
exit(98);
}

/**
 * multiply - multiplies two positive numbers represented as strings
 * @num1: the first number to multiply
 * @num2: the second number to multiply
 *
 * Return: a string containing the product of num1 and num2
 */
char *multiply(char *num1, char *num2)
{
int len1 = 0, len2 = 0, i, j, k, carry = 0, sum = 0;
char *result;

while (num1[len1])
{
if (!_isdigit(num1[len1]))
print_error();
len1++;
}
while (num2[len2])
{
if (!_isdigit(num2[len2]))
print_error();
len2++;
}
result = malloc(sizeof(char) * (len1 + len2 + 1));
if (result == NULL)
return (NULL);

for (i = 0; i < len1 + len2; i++)
result[i] = '0';
result[i] = '\0';

for (i = len1 - 1; i >= 0; i--)
{
carry = 0;
for (j = len2 - 1; j >= 0; j--)
{
sum = (num1[i] - '0') * (num2[j] - '0') + carry + (result[i + j + 1] - '0');
carry = sum / 10;
result[i + j + 1] = (sum % 10) + '0';
}
result[i + j + 1] = carry + '0';
}

i = 0;
while (result[i] == '0' && result[i + 1] != '\0')
i++;
(void)k;
return (result + i);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
char *num1, *num2, *product;

if (argc != 3)
print_error();

num1 = argv[1];
num2 = argv[2];

product = multiply(num1, num2);
if (product == NULL)
return (98);

printf("%s\n", product);

free(product);

return (0);
}
