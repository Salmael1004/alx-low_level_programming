#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character \ should be printed
 */
void print_diagonal(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	} else
	{
		int c, t;

		for (c = 0; c < n; c++)
		{
			for (t = 0; t < n; t++)
			{
				if (t == c)
					_putchar('\\');
				else if (t < c)
					_putchar(' ');
			}
			_putchar('\n');
		}
	}
}
