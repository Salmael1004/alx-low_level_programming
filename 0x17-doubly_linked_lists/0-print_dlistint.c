#include "lists.h"

/**
 * print_dlistint - print value of all nodes
 * @h: pointer to start list
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t zb1 = 0;

	if (h == NULL)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		zb1++;
		h = h->next;
	}

	return (zb1);
}
