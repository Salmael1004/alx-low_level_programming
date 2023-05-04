#include "main.h"

/**
 * set_bit - the value of a bit to 1 at a given index.
 * @index: starting from 0 of the bit you want to set
 * @n: pointer number of go
 *
 * Return: 1 of it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int go;

	if (index > 64)
		return (-1);

	for (go = 1; index > 0; index--, go *= 2)
		;
	*n += go;

	return (1);
}
