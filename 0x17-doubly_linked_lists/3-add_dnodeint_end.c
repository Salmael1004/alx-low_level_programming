#include "lists.h"

/**
 * add_dnodeint_end - Add new node at the end of dlistint_t list
 * @head: The head of list
 * @n: The value of new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tmp = *head;
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;

	return (new);
}
