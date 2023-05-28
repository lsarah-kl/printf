#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/* Function protoypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_binary(va_list args);
int print_percent(va_list args);

#endif /* MAIN_H */
