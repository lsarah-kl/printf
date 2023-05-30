#include "main.h"
#include <stdio.h>

/**
 * get_size - Function that calculates the size to give the argument
 * @format: Formatted string where we print the arguments
 * @i: List of args to be printed.
 *
 * Return: Precision.
 */

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

