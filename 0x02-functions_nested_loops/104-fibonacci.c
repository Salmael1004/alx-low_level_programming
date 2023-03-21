#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int n, c, t, c1, c2, t1, t2;

	c = 1;
	t = 2;

	printf("%lu", c);

	for (n = 1; n < 91; n++)
	{
		printf(", %lu", t);
		t = t + c;
		c = t - c;
	}

	c1 = c / 1000000000;
	c2 = c % 1000000000;
	t1 = t / 1000000000;
	t2 = t % 1000000000;

	for (n = 92; n < 99; ++n)
	{
		printf(", %lu", t1 + (t2 / 1000000000));
		printf("%lu", t2 % 1000000000);
		t1 = t1 + c1;
		c1 = t1 - c1;
		t2 = t2 + c2;
		c2 = t2 - c2;
	}

	printf("\n");

	return (0);
}
