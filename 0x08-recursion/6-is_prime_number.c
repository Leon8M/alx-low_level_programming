#include "main.h"

/**
 * is_prime_number - checks if a number is prime
 *
 * @n: the number to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_number(int n)

if (n <= 1) 
return 0;
return is_prime_helper(n, 2);
}

/**
 * is_prime_helper - helper function for is_prime_number
 *
 * @n: the number to check
 * @i: the current divisor to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */
int is_prime_helper(int n, int i)
{
if (n % i == 0 && i != n)
return 0;
else if (i == n)
return 1;
else
return is_prime_helper(n, i + 1);
}
