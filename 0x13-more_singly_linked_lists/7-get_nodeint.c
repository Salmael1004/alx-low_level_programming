#include "lists.h"

/**
 * get_nodeint_at_index - the nth node of a listint_t linked list
 * @head: pointer of the first node
 * @index: index is the index of the node
 *
 * Return: pointer of Index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t i;

	for (i = 0; (i < index) && (head->next); i++)
		head = head->next;

	if (i < index)
		return (NULL);

	return (head);
}
