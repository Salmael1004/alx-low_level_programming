#include <stdio.h>

/**
 * main - prints all possible different combinations of digits
 * Must be followed by a new line, putchar used six times
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n, c, t;

	for (n = 48; n < 58; n++)
	{
		for (c = 49; c < 58; c++)
		{
			for (t = 50; t < 58; t++)
			{
				if (t > c && c > n)
				{
					putchar(n);
					putchar(c);
					putchar(t);
					if (n != 55 || c != 56)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
