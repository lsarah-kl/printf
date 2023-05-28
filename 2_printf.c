#include "main.h"

/**
 * _printf - Function tht prints formatted output to stdout.
 * @format: Pointer to a character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;

	va_start(args, format);

	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
				printed_chars += print_char(args);
			else if (format[i] == 's')
				printed_chars += print_string(args);
			else if (format[i] == 'b')
				printed_chars += print_binary(args);
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				printed_chars++;
			}
		}
		i++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * print_char - Function that prints a single character.
 * @args: The va_list argument containing the character to print.
 *
 * Return: 1 (the number of chars printed).
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Function that prints a string of characters.
 * @args: The va_list argument containing the string to print.
 *
 * Return: The number of chars printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		printed_chars++;
	}

	return (printed_chars);
}

/**
 * print_binary - Function that prints an unsigned int in binary format.
 * @args: The va_list argument containing unsigned int to print.
 *
 * Return: The number of chars printed.
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int printed_chars = 0;
	char binary[32];
	int i = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num > 0)
	{
		binary[i] = num % 2 + '0';
		num /= 2;
		i++;
	}

	while (i > 0)
	{
		write(1, &binary[i - 1], 1);
		printed_chars++;
		i--;
	}

	return (printed_chars);
}

/**
 * print_percent - Function that prints a percent character.
 * @args: The va_list argument (unused).
 *
 * Return: 1 (the number of chars printed).
 */
int print_percent(va_list args)
{
	UNUSED(args);
	write(1, "%", 1);
	return (1);
}
