#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - function that frees a list
 * @head: pointer to list
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *zb1;

	if (head == NULL)
		return;

	while (*head)
	{
		zb1 = *head;
		*head = (*head)->next;
		free(zb1);
	}

	head = NULL;
}
