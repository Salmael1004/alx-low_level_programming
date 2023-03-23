#include "main.h"

/**
 * print_triangle - prints a triangle, followd by a new line
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	} else
	{
		int n, c;

		for (n = 1; n <= size; n++)
		{
			for (c = n; c < size; c++)
			{
				_putchar(' ');
			}

			for (c = 1; c <= n; c++)
			{
				_putchar('#');
			}

			_putchar('\n');
		}
	}
}
