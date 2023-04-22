#include "main.h"

/**
 * print_str - Prints a string to stdout
 * @c: The string to print
 *
 * Return: The number of characters printed
 */
int print_str(char *c)
{
	int count = 0;

	while (c && *c)
	{
		putchar(*c++);
		count++;
	}

	return (count);
}

/**
 * print_address - Prints the memory address of a pointer argument
 *
 * @args: A va_list containing the pointer argument
 * Return: The number of characters printed
 */
int print_address(va_list args)
{
	unsigned long int p = (unsigned long int)va_arg(args, void *);
	char *str = "0x";
	int i, j, count = 0;

	count += print_str(str);

	if (p == 0)
	{
		count += putchar('0');
		return (count);
	}

	for (i = 0; p >> (i * 4 + 4); i++)
		;

	for (; i >= 0; i--)
	{
		j = (p >> (i * 4)) & 0xf;
		if (j < 10)
			count += putchar('0' + j);
		else
			count += putchar('a' + j - 10);
	}

	return (count);
}
