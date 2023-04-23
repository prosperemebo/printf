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

	_putchar(c);

	return (1);
}
