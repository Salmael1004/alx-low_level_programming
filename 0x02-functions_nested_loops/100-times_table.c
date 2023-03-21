#include "main.h"

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: number of the times table
 */
void print_times_table(int n)
{
	int c, t, z;

	if (n >= 0 && n <= 15)
	{
		for (c = 0; c <= n; c++)
		{
			for (t = 0; t <= n; t++)
			{
				z = t * c;
				if (t == 0)
				{
					_putchar(z + '0');
				} else if (z < 10 && t != 0)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar(' ');
					_putchar(z + '0');
				} else if (z >= 10 && z < 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar(' ');
					_putchar((z / 10) + '0');
					_putchar((z % 10) + '0');
				} else if (z >= 100)
				{
					_putchar(',');
					_putchar(' ');
					_putchar((z / 100) + '0');
					_putchar(((z / 10) % 10) + '0');
					_putchar((z % 10) + '0');
				}
			}
			_putchar('\n');
		}
	}
}
