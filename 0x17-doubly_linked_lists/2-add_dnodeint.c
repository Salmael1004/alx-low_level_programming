#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *zb1;

	if (!head)
		return (NULL);

	zb1 = malloc(sizeof(dlistint_t));
	if (!zb1)
		return (NULL);

	zb1->n = n;

	zb1->next = *head;
	zb1->prev = NULL;

	if (*head)
		(*head)->prev = zb1;

	*head = zb1;

	return (zb1);
}
