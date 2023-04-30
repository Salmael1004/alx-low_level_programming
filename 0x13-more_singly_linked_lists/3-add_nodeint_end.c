#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint_end - add node at end of a listint_t list.
  *
  * @head: head of double pointer
  * @n: int add the list
  * Return: NULL if it failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *end_node;
	listint_t *t = *head;

	if (head == NULL)
		return (NULL);
	end_node = malloc(sizeof(listint_t));
	if (end_node == NULL)
		return (NULL);
	end_node->n = n;
	end_node->next = NULL;
	if (*head == NULL)
	{
	*head = end_node;
		return (end_node);
	}
	t = *head;
	while (t->next != NULL)
	{
		t = t->next;
	}
	t->next = end_node;
	return (end_node);
}
