#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Function protoypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_binary(va_list args);
int print_percent(va_list args);
void print_buffer(char buffer[], int *buff_ind);
int handle_print_char(va_list args, char buffer[], int *buff_ind);
int handle_print_string(va_list args, char buffer[], int *buff_ind);
int handle_print_binary(va_list args, char buffer[], int *buff_ind);

#endif /* MAIN_H */
