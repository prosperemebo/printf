#include "main.h"

/**
 * print_char - Print Char function to print character
 *
 * @args: va_list containing characters to print
 * Return: Number of printed characters;
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	putchar(c);

	return (1);
}

/**
 * print_string - Print String function to print string
 *
 * @args: va_list containing string to print
 * Return: Number of printed characters in string
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	while (*s != '\0')
	{
		putchar(*s);
		s++;
		count++;
	}

	return (count);
}

/**
 * print_percent - Print percent function to print percent
 *
 * Return: (1)
 */
int print_percent(void)
{
	putchar('%');

	return (1);
}

/**
 * print_int - Print int function to print integer or unsigned int
 *
 * @args: va_list containing string to print
 * Return: Number of printed characters in int
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	int digitCount = 0;
	int count = 0;
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
		digits[i] = (char)(num % 10 + '0');
		num /= 10;
	}

	for (j = digitCount - 1; j >= 0; j--)
	{
		putchar(digits[j]);
		count++;
	}

	return (count);
}

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
	    {'\0', NULL}};
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '%')
				count += print_percent();

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
