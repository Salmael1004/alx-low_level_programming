#include "lists.h"

/**
 * get_dnodeint_at_index - Return the nth node of a dlistint_t linked list
 * @head: The head of list
 * @index: The index of node, starting from 0
 * Return: The nth node, or NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int zb1;

	if (head == NULL)
		return (NULL);

	for (zb1 = 0; zb1 < index; zb1++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}

	return (head);
}
