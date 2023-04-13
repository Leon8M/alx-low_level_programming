#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * array_range - creates an array of integers from min to max (inclusive)
 * @min: the minimum value of the range
 * @max: the maximum value of the range
 *
 * Return: pointer to the newly created array
 *         or NULL if min > max or malloc fails
 */
int *array_range(int min, int max)
{
int *arr;
int size, i;

if (min > max)
return (NULL);

size = max - min + 1;
arr = malloc(size * sizeof(int));
if (arr == NULL)
return (NULL);

for (i = 0; i < size; i++)
arr[i] = min++;

return (arr);
}
