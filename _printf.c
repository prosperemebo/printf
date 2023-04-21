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

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			// Handling %c directive
			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);
				putchar(c);
				count++;
			}

			// Handling %s directive
			else if (*format == 's') 
			{
				char *s = va_arg(args, char *);
				
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
				
			}

			// Handling %
			else if (*format == '%')
			{
				putchar('%');
				count++;
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
