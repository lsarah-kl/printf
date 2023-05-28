#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/* Functions that prints chars and strings */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Functions that prints numbers */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function that prints non-printable characters */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function that prints memory address */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Functions that handles other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function that prints string in reverse */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Function that prints a string in rot 13 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

#endif /* MAIN_H */
