#include "main.h"

/**
 * print_hex - Print unsigned int function to print integer or unsigned int
 *
 * @args: va_list containing string to print
 * @uppercase: int
 * Return: Number of printed characters in int
 */
int print_hex(va_list args, int uppercase)
{
        unsigned int num = va_arg(args, unsigned int);
        char hex_digits[] = "0123456789abcdef";
        int digitCount = 0;
        int count = 0;
        int temp, i, j;
        char *digits;

        temp = num;
        while (temp != 0)
        {
                digitCount++;
                temp /= 16;
        }
        digits = (char *)malloc(sizeof(char) * (digitCount + 1));
        for (i = 0; i <= digitCount; i++)
        {
                digits[i] = hex_digits[num % 16];
                num /= 16;
        }
        digits[digitCount] = '\0';
        if (uppercase)
        {
                for (j = digitCount - 1; j >= 0; j--)
                {
                        putchar(toupper(digits[j]));
                        count++;
                }
        }
        else
        {
                for (j = digitCount - 1; j >= 0; j--)
                {
                        putchar(digits[j]);
                        count++;
                }
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
        return (print_hex(args, 0));
}

/**
 * print_hex_upper - Prints number in hexadecimal in uppercase
 *
 * @args: List with numbers to be printed
 * Return: number of printed characters
 */
int print_hex_upper(va_list args)
{
        return (print_hex(args, 1));
}
