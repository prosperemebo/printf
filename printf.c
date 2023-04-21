#include "main.h"

int main(void)
{
	char c = 'H';
	char s[] = "world";

	int count = _printf("%cello, %s!", c, s);

	printf("\nTotal number of characters printed: %d\n", count);

	return (0);
}
