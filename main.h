#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(char format);
int print_int(va_list args);
int print_unint(va_list args);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_address(va_list args);

/**
 * struct print_func - Struct for function pointer to print function
 *
 * @type: Format Specifier
 * @execute: Method to handle format specifier
 */
typedef struct print_func
{
        char type;
        int (*execute)(va_list);
} print_func_t;

#endif
