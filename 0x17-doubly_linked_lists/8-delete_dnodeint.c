#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete the node at the specified index
 * @head: The head of the list
 * @index: The index, starting at 0
 *
 * Return: 1 if successful, -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *zero = *head;
	unsigned int base;

	if (!head || !(*head))
		return (-1);

	for (base = 0; base < index; base++)
	{
		zero = zero->next;
		if (zero == NULL)
			return (-1);
	}

	if (index == 0)
	{
		if (zero->next)
			zero->next->prev = NULL;
		*head = zero->next;
	}
	else
	{
		if (zero->next)
			zero->next->prev = zero->prev;
		if (zero->prev)
			zero->prev->next = zero->next;
	}

	free(zero);
	return (1);
}
