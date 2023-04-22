#include "main.h"

int main(void)
{
	char c = 'H';
	char s[] = "world";
	int i = 123;
	int j = -7689;

	int count = _printf("%cello, %s! %d %d", c, s, i, j);

	printf("\nTotal number of characters printed: %d\n", count);

	return (0);
}
