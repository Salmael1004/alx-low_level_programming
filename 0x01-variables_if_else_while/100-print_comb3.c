#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Must be followed by a new line, and use putchar only five times
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, c;

	for (n = 48; n <= 56; n++)
	{
		for (c = 49; c <= 57; c++)
		{
			if (c > n)
			{
				putchar(n);
				putchar(c);
				if (n != 56 || c != 57)
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
