#include "main.h"
#include <unistd.h>

/**
 * write_flag - Write the character in order to call
 * @c: character in order
 * Return: success 1
 * On error, return -1 and errno is set appropriately.
 * Description: BUFFER_SIZE = 1024
 */
int write_flag(const char *format, int *i, va_list list)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
	}

/**
 * def printf(format_string, *args):
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _write(char *str, *buf, int fd)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		printf(str[i]);
	return (i);
}
