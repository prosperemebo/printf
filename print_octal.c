#include "main.h"

/**
 * print_octal - Print unsigned int function to print integer or unsigned int
 *
 * @args: va_list containing string to print
 * Return: Number of printed characters in int
 */
int print_octal(va_list args)
{
        unsigned int num = va_arg(args, unsigned int);
        int digitCount = 0;
        int count = 0;
        int temp, i, j;
        char *digits;

        temp = num;
        while (temp != 0)
        {
                digitCount++;
                temp /= 8;
        }

        digits = (char *)malloc(sizeof(char) * (digitCount + 1));

        for (i = 0; i <= digitCount; i++)
        {
                digits[i] = (char)(num % 8 + '0');
                num /= 8;
        }

        for (j = digitCount - 1; j >= 0; j--)
        {
                putchar(digits[j]);
                count++;
        }

        return (count);
}
