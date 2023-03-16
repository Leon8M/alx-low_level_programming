#include <unistd.h>
/**
 * main - Entry point
 *
 * Return: Always 1 (Success)
 */
int main(void)
{
const char message[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
ssize_t len = sizeof(message) - 1;
ssize_t ret = write(STDERR_FILENO, message, len);
return ret != len;
}
