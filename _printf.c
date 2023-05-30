#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: Format string.
 *
 * Return: Number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */

			/* Handle conversion specifiers */
			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					printed_chars += _print_string(va_arg(args, char *));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				default:
					/* Handle invalid conversion specifier */
					printed_chars += _putchar('%');
					printed_chars += _putchar(*format);
					break;
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return printed_chars;
}

