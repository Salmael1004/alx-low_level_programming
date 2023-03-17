#include <stdio.h>

/**
 * main - prints all numbers of base 16 in lowercase,
 * followed by a new line, using putchar three times
 * Return: Always 0 (Success)
 */
int main(void)
{
	char n;

	for (n = '0'; n <= '9'; n++)
	{
		putchar(n);
	}
	for (n = 'a'; n <= 'f'; n++)
	{
		putchar(n);
	}
	putchar('\n');
	return (0);
}
