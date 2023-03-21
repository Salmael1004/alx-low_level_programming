#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int n, c, t;

	for (n = 0; n < 10; n++)
	{
		for (c = 0; c < 10; c++)
		{
			t = c * n;
			if (c == 0)
			{
				_putchar(t + '0');
			}

			if (t < 10 && c != 0)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(t + '0');
			} else if (t >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((t / 10) + '0');
				_putchar((t % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
