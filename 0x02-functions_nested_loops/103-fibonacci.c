#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	unsigned long int c, t, next, sum;

	c = 1;
	t = 2;
	sum = 0;

	for (n = 0; n <= 33; ++n)
	{
		if (c < 4000000 && (c % 2) == 0)
		{
			sum = sum + c;
		}
		next = c + t;
		c = t;
		t = next;
	}

	printf("%lu\n", sum);

	return (0);
}
