#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * error_usage - prints usage error message
 */
void error_usage(void)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

/**
 * error_cant_read - prints read error message
 * @file: the name of the file that cannot be read
 */
void error_cant_read(char *file)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
exit(98);
}

/**
 * error_cant_write - prints write error message
 * @file: the name of the file that cannot be written
 */
void error_cant_write(char *file)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
exit(99);
}

/**
 * error_cant_close - prints close error message
 * @fd: the file descriptor that cannot be closed
 */
void error_cant_close(int fd)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}

/**
 * cp - copies the content of a file to another file
 * @file_from: the name of the file to copy from
 * @file_to: the name of the file to copy to
 */
void cp(char *file_from, char *file_to)
{
int fd_from, fd_to, n_read, n_write;
char buffer[1024];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
error_cant_read(file_from);

fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd_to == -1)
error_cant_write(file_to);

while ((n_read = read(fd_from, buffer, 1024)) > 0)
{
n_write = write(fd_to, buffer, n_read);
if (n_write != n_read)
error_cant_write(file_to);
}
if (n_read == -1)
error_cant_read(file_from);

if (close(fd_from) == -1)
error_cant_close(fd_from);
if (close(fd_to) == -1)
error_cant_close(fd_to);
}

/**
 * main - entry point
 * @argc: the number of arguments passed to the program
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
if (argc != 3)
error_usage();

cp(argv[1], argv[2]);

return (0);
}
