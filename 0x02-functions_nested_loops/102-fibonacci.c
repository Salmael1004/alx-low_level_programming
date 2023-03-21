#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n, c, t, next;

	c = 1;

	t = 2;

	for (n = 1; n <= 50; ++n)
	{
		if (c != 20365011074)
		{
			printf("%ld, ", c);
		} else
		{
			printf("%ld\n", c);
		}
		next = c + t;
		c = t;
		t = next;
	}

	return (0);
}
