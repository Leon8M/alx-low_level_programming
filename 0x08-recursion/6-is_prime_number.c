#include "main.h"

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);

for (int i = 2; i < n; i++)
{
if (n % i == 0)
return (0);
}

return (1);
}
