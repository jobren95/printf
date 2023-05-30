#include "main.h"

/**
 * jo_qv08 -  Function that calculates the precision for printing
 * @format: Formatted array in which to print the arguments
 * @i: Counts of arguments to be printed.
 * @list: Counts of arguments.
 *
 * Return: Precision.
 */
int jo_qv08(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

