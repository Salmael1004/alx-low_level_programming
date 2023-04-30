#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node
 * @head: a double pointer
 *
 * Return: head node's data (n)
 *         or 0 - if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *zb1;
	int n;

	zb1 = *head;

	if (zb1 == NULL)
		return (0);

	*head = zb1->next;
	n = zb1->n;

	free(zb1);
	return (n);
}
