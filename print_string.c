#include "main.h"

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
