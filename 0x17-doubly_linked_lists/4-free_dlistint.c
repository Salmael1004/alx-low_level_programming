#include "lists.h"

/**
 * free_dlistint - Free a dlistint_t
 * @head: The head of list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
