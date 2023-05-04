#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int energy, power;
	int chemistry;

	if (b == NULL)
		return (0);

	for (chemistry = 0; b[chemistry]; chemistry++)
	{
		if (b[chemistry] != '0' && b[chemistry] != '1')
			return (0);
	}

	for (power = 1,
		      energy = 0,
		      chemistry--;
			chemistry >= 0;
			chemistry--,
				power *= 2)
	{
		if (b[chemistry] == '1')
			energy += power;
	}

	return (energy);
}
