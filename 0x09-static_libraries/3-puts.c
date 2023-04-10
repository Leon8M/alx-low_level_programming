#include "main.h"

#include <unistd.h>

/**
 * _puts - writes a string to stdout
 * @s: the string to write
 */
void _puts(char *s)
{
while (*s)
write(1, s++, 1);
}
