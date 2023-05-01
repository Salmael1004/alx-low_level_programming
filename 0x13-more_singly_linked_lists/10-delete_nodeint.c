#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *new, *jeans;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		jeans = (*head)->next;
		free(*head);
		*head = jeans;
		return (1);
	}
	new = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (new->next == NULL)
			return (-1);
		new = new->next;
	}
	jeans = new->next;
	new->next = jeans->next;
	free(jeans);
	return (1);

}
