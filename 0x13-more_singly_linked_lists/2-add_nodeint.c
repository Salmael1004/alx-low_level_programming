#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a node to the beginning of a linked list
 * @head: pointer to the head of the list
 * @n: integer to be used as content
 *
 * Return: address of the newly added node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *beg_node;

	beg_node = malloc(sizeof(listint_t));
	if (beg_node != NULL)
	{
		beg_node->n = n;
		beg_node->next = *head;
	}
	else
		return (NULL);
	if (*head != NULL)
		beg_node->next = *head;
	*head = beg_node;
	return (beg_node);
}
