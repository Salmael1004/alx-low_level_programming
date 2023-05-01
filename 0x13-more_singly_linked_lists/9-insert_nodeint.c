#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int z;
	listint_t *nct, *dream;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		nct = *head;
		for (z = 0; z < idx - 1 && nct != NULL; z++)
		{
			nct = nct->next;
		}
		if (nct == NULL)
			return (NULL);
	}
	dream = malloc(sizeof(listint_t));
	if (dream == NULL)
		return (NULL);
	dream->n = n;
	if (idx == 0)
	{
		dream->next = *head;
		*head = dream;
		return (dream);
	}
	dream->next = nct->next;
	nct->next = dream;
	return (dream);
}
