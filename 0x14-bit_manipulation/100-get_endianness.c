#include <stdlib.h>
#include "main.h"

/**
 * get_endianness - check endianness
 *
 * Return: 0 if big endian, or 1 if little endian
 */
int get_endianness(void)
{
	int endian_check;
	char *byte_ptr;

	endian_check = 1;
	byte_ptr = (char *)&endian_check;

	if (*byte_ptr == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
