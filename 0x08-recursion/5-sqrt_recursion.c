#include "main.h"

/**
 * sqrt_helper - finds the natural square root of a number using recursion.
 *
 * @n: the number to find the square root of.
 * @low: the lower bound of the possible square root.
 * @high: the upper bound of the possible square root.
 *
 * Return: the natural square root of n, or -1 if n does not have a natural square root.
 */
int sqrt_helper(int n, int low, int high)
{
int mid;

if (high < low)
{
return (-1);
}

mid = (low + high) / 2;

if (mid * mid == n)
{
return (mid);
}
else if (mid * mid > n)
{
return (sqrt_helper(n, low, mid - 1));
}
else
{
return (sqrt_helper(n, mid + 1, high));
}
}

/**
 * _sqrt_recursion - returns the natural square root of a number.
 *
 * @n: the number to find the square root of.
 *
 * Return: the natural square root of n, or -1 if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
if (n < 0)
{
return (-1);
}
else if (n == 0 || n == 1)
{
return (n);
}
else
{
return (sqrt_helper(n, 1, n));
}
}
