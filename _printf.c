#include "main.h"
#include <unistd.h>

/**
 * _printf - Function that prints formatted output to stdout
 * @format: Format string
 *
 * Return: Num of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char c;
	char *s;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					printed_chars++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						write(1, s, 1);
						s++;
						printed_chars++;
					}
					break;
				case '%':
					write(1, "%", 1);
					printed_chars++;
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					printed_chars += 2;
					break;
			}
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

