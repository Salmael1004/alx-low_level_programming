#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees a listint_t list
 * @head: the head of the list
 *
 * Return: NULL if error
 */
void free_listint(listint_t *head)
{
	listint_t *oze;

	while (head != NULL)
	{
		oze = head->next;
		free(head);
		head = oze;
	}
}
