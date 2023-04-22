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

			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);
				putchar(c);
				count++;
			}

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

			else if (*format == '%')
			{
				putchar('%');
				count++;
			}

			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				int digitCount = 0;
				int temp, i, j;
				char *digits;

				if (num < 0)
				{
					putchar('-');
					count++;
					num = -num;
				}

				temp = num;
				while (temp != 0)
				{
					digitCount++;
					temp /= 10;
				}

				digits = (char *)malloc(sizeof(char) * (digitCount + 1));

				for (i = 0; i <= digitCount; i++)
				{
					digits[i] = (char) (num % 10 + '0');
					num /= 10; 
				}

				for (j = digitCount - 1; j >= 0; j--)
				{
					putchar(digits[j]);
					count++;
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
