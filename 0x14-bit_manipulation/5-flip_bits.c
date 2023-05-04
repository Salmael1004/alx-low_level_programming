#include <stdio.h>
#include "main.h"

/**
 * flip_bits - flip to get from one number to another.
 * @n: the first number
 * @m: the second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int zero = n ^ m;
	unsigned int flipper = 0;

	while (zero != 0)
	{
		flipper += zero & 1;
		zero >>= 1;
	}

	return (flipper);
}
