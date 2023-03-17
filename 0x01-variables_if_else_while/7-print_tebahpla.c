#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, in reverse,
 * followed by a new line, using putchar
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;

	for (n = 'z'; n >= 'a'; n--)
	{
		putchar(n);
	}
	putchar('\n');
	return (0);
}
