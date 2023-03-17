#include <stdio.h>

/**
 * main - prints all possible different combinations of digits
 * Must be followed by a new line, putchar used six times
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n, c, t;

	for (n = 0; n < 8; n++)
	{
		for (c = 1; c < 9; c++)
		{
			for (t = 2; t < 10; t++)
			{
				putchar('0' + n);
				putchar('0' + c);
				putchar('0' + t);
				if (n < 7 || c < 8 || t < 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
