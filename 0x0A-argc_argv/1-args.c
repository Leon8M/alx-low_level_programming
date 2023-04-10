#include "main.h"
#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: the number of arguments passed into the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
(void)argv;
printf("%d\n", argc - 1);

return (0);
}
