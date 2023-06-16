#include "lists.h"

/**
 * dlistint_len - Return the number of elements in a dlistint_t list
 * @h: pointer to The list
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t zb1 = 0;

	while (h)
	{
		zb1++;
		h = h->next;
	}

	return (zb1);
}
