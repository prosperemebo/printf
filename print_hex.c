#include "main.h"

/**
 * print_hex - Print unsigned int function to print integer or unsigned int
 *
 * @args: va_list containing string to print
 * @flag: int
 * Return: Number of printed characters in int
 */
int print_hex(va_list args, int flag)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex[100];
	int i, count = 0;

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	for (i = 0; n > 0; i++)
	{
		int remainder = n % 16;

		if (remainder < 10)
			hex[i] = remainder + '0';
		else if (flag == 1)
			hex[i] = remainder + 'a' - 10;
		else
			hex[i] = remainder + 'A' - 10;

		n /= 16;
	}

	for (i--; i >= 0; i--)
	{
		count += _putchar(hex[i]);
	}

	return (count);
}

/**
 * print_hex_lower - Prints number in hexadecimal in lowercase
 *
 * @args: List with numbers to be printed
 * Return: number of printed characters
 */
int print_hex_lower(va_list args)
{
	return (print_hex(args, 1));
}

/**
 * print_hex_upper - Prints number in hexadecimal in uppercase
 *
 * @args: List with numbers to be printed
 * Return: number of printed characters
 */
int print_hex_upper(va_list args)
{
	return (print_hex(args, 0));
}
