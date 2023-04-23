#include "main.h"

/**
 * process_format - processes the format string and returns
 * the count of printed characters
 *
 * @format: A pointer to the format string
 * @args: A va_list containing the arguments to be printed
 * Return: The count of printed characters
 */
int process_format(const char *format, va_list args)
{
	int i, count = 0;
	print_func_t methods[] = {
	    {'c', print_char},
	    {'s', print_string},
	    {'d', print_int},
	    {'i', print_int},
	    {'u', print_unint},
	    {'o', print_octal},
	    {'x', print_hex_lower},
	    {'X', print_hex_upper},
	    {'p', print_address},
	    {'\0', NULL}};

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += print_percent(*format);
			if (*format == 'r')
				_putchar('%');
			_putchar('r');
			count++;
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
			_putchar(*format);
			count++;
		}
		format++;
	}
	return count;
}

/**

_printf - prints a formatted string to stdout

@format: A pointer to the format string

Return: The count of printed characters
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	if (!format)
		return (-1);

	va_start(args, format);

	count = process_format(format, args);

	va_end(args);

	return count;
}
