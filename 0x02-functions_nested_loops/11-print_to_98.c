#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98,
 * followed by a new line
 * @n: prints from this number
 */
void print_to_98(int n)
{
	int c, t;

	if (n <= 98)
	{
		for (c = n; c <= 98; c++)
		{
			if (c != 98)
				printf("%d, ", c);
			else if (c == 98)
				printf("%d\n", c);
		}
	} else if (n >= 98)
	{
		for (t = n; t >= 98; t--)
		{
			if (t  != 98)
				printf("%d, ", t);
			else if (t == 98)
				printf("%d\n", t);
		}
	}
}
