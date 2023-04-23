#include "main.h"

/**
 * _puts - Prints input string to stdout
 *
 * @str: pointer to the string to print
 * Return: number of characters printed
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
