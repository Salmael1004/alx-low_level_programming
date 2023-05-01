#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *past, *present;

	if (head == NULL || *head == NULL)
		return (NULL);

	if ((*head)->next == NULL)
		return (*head);

	past = NULL;
	while (*head != NULL)
	{
		present = (*head)->next;
		(*head)->next = past;
		past = *head;
		*head = present;
	}
	*head = past;
	return (*head);
}
