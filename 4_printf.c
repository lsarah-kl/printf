#include "main.h"

/**
 * _printf - Function that prints formatted output to stdout.
 * @format: Pointer to a character string containing format specifiers.
 *
 * Return: The number of chars printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[BUFF_SIZE];
	int buff_ind = 0;
	int printed_chars = 0;
	int i = 0;

	va_start(args, format);

	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += buff_ind;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			if (format[i] == 'c')
				printed_chars += handle_print_char(args, buffer, &buff_ind);
			else if (format[i] == 's')
				printed_chars += handle_print_string(args, buffer, &buff_ind);
			else if (format[i] == 'b')
				printed_chars += handle_print_binary(args, buffer, &buff_ind);
			else if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					printed_chars += buff_ind;
				}
			}
		}
		i++;
	}

	print_buffer(buffer, &buff_ind);
	printed_chars += buff_ind;

	va_end(args);

	return (printed_chars);
}

/**
 * handle_print_char - Function thta handles printing a single character.
 * @args: The va_list argument containing the character to print.
 * @buffer: The buffer to store the character.
 * @buff_ind: Pointer to buffer index.
 *
 * Return: 1 (the number of chars printed).
 */
int handle_print_char(va_list args, char buffer[], int *buff_ind)
{
	char c = va_arg(args, int);
	buffer[(*buff_ind)++] = c;
	return (1);
}

/**
 * handle_print_string - Function that handles printing a string of characters.
 * @args: The va_list argument containing the string to print.
 * @buffer: The buffer to store the string.
 * @buff_ind: Pointer to buffer index.
 *
 * Return: The number of chars printed.
 */
int handle_print_string(va_list args, char buffer[], int *buff_ind)
{
	char *str = va_arg(args, char *);
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		buffer[(*buff_ind)++] = *str;
		if (*buff_ind == BUFF_SIZE)
		{
			print_buffer(buffer, buff_ind);
			printed_chars += *buff_ind;
		}
		str++;
		printed_chars++;
	}

	return (printed_chars);
}

/**
 * handle_print_binary - Function that handles printing an unsigned int in binary format.
 * @args: The va_list argument containing the unsigned int to print.
 * @buffer: The buffer to store the binary representation.
 * @buff_ind: Pointer to buffer index.
 *
 * Return: The number of chars printed.
 */
int handle_print_binary(va_list args, char buffer[], int *buff_ind)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = 0;
	char binary[32];
}
