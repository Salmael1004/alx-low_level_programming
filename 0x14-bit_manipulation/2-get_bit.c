#include <stdlib.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: checking bits
 * @index: which to check bit
 *
 * Return: the value of the bit at index, -1 error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int dracula;

	if (index > 64)
		return (-1);

	dracula = n >> index;

	return (dracula & 1);
}
