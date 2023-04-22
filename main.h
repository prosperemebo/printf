#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);

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
