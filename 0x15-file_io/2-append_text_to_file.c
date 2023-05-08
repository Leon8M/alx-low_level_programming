#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Pointer to the name of the file.
 * @text_content: Pointer to the NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 *         If filename is NULL return -1.
 *         If text_content is NULL, do not add anything to the file.
 *         Return 1 if the file exists and -1 if the file does not exist or if
 *         you do not have the required permissions to write the file.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int fd, ret_val, i = 0;

if (filename == NULL)
return (-1);

if (access(filename, F_OK) == -1)
return (-1);

if (text_content == NULL)
return (1);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

while (text_content[i])
i++;

ret_val = write(fd, text_content, i);
if (ret_val == -1)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
