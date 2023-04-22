#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 *
 * @format: Input string containing zero or more directives
 * Return: Number of printed characters excluding null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;
	print_func_t methods[] = {
	    {'c', print_char},
	    {'s', print_string},
	    {'d', print_int},
	    {'i', print_int},
	    {'u', print_unint},
	    {'o', print_octal},
	    {'x', print_hex_lower},
	    {'X', print_hex_upper},
	    {'\0', NULL}};
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%' || *format == 'r')
				count += print_percent(*format);
			for (i = 0; methods[i].type != '\0'; i++)
			{
				if (methods[i].type == *format)
				{
					count += methods[i].execute(args);
					break;
				}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
