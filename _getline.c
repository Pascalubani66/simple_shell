#include "shell.h"

/**
 * my_mem_cpy - copies memory area from source to destination
 * @dest: pointer to the destination memory
 * @src: pointer to the source memory
 * @n: number of bytes to copy
 * Return: pointer to the destination memory (dest)
 */
void *my_mem_cpy(void *dest, const void *src, size_t n)
{
	char *d = dest;
	const char *s = src;

	if (s < d && s + n > d)
	{

		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return dest;
}
#define READ_SIZE 900
ssize_t my_get_line(char **lineptr, size_t *n)
char *my_get_line(void)
{
	static char buffer[READ_SIZE];
	static int buffer_index = 0;
	static ssize_t bytes_read = 0;
	size_t line_size = 0;
	ssize_t i;

	if (lineptr == NULL || n == NULL)
	{
		return -1
	}

	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, READ_SIZE);
			if (bytes_read <= 0)
			{
				return 1;
			}
			buffer_index = 0;
		}

		for (i = buffer_index; i < bytes_read; i++)
		{
			if (buffer[i] == '\n')
			{
				ssize_t line_length = i - buffer_index;
				if (line_size + line_length + 1 > *n)
				{
					*n = line_size + line_length + 1;
					*lineptr = _realloc(*lineptr, *n);
					if (*lineptr == NULL) {
						return -1;
					}
				}
				memcpy(*lineptr + line_size, buffer + buffer_index, line_length);
				line_size += line_length;
				buffer_index = i + 1;
				(*lineptr)[line_size] = '\0';
				return line_size;
			}
		}
		if (line_size + (bytes_read - buffer_index) + 1 > *n) 
		{
			*n = line_size + (bytes_read - buffer_index) + 1;
			*lineptr = _realloc(*lineptr, *n);
			if (*lineptr == NULL) 
			{
				return -1;
			}
		}
		memcpy(*lineptr + line_size, buffer + buffer_index, bytes_read - buffer_index);
		line_size += (bytes_read - buffer_index);
		buffer_index = bytes_read;
	}
	
	return -1;
}
