#include <stdio.h>
#include <math.h>

/**
 * main - finds and print the largest prime factor of the number 612852475143
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int n;
	long int max;
	long int c;

	n = 612852475143;
	max = -1;

	while (n % 2 == 0)
	{
		max = 2;
		n /= 2;
	}

	for (c = 3; c <= sqrt(n); c = c + 2)
	{
		while (n % c == 0)
		{
			max = c;
			n = n / c;
		}
	}

	if (n > 2)
		max = n;

	printf("%ld\n", max);

	return (0);
}
