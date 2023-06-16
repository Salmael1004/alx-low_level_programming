#include "lists.h"

/**
 * insert_dnodeint_at_index - insert node at a position
 * @h: The head of list
 * @idx: The index, starting at 0
 * @n: The value of new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *zero = *h;
	dlistint_t *base;
	unsigned int zb1;

	if (!h)
		return (NULL);
	if (*h == NULL && idx != 0)
		return (NULL);
	base = malloc(sizeof(dlistint_t));
	if (base == NULL)
		return (NULL);
	base->n = n;
	if (idx == 0)
	{
		if (*h)
			zero->prev = base;
		*h = base;
		base->prev = NULL;
		base->next = zero;
		return (base);
	}
	for (zb1 = 1; zb1 < idx; zb1++)
	{
		zero = zero->next;
		if (zero == NULL)
		{
			free(base);
			return (NULL);
		}
	}
	base->prev = zero;
	base->next = zero->next;
	if (zero->next)
		zero->next->prev = base;
	zero->next = base;
	return (base);
}
