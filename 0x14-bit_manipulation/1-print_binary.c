#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	int number = 0;
	unsigned long int temp = n;

	while (temp != 0)
	{
		number++;
		temp >>= 1;
	}

	if (number == 0)
	{
		putchar('0');
	}
	else
	{
		while (number > 0)
		{
			number--;
			if ((n >> number) & 1)
			{
				putchar ('1');
			}
			else
			{
				putchar('0');
			}
		}
	}
}
