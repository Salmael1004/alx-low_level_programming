#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list.
 * @head: double pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t len = 0;
	listint_t *current = *head;

	while (current)
	{
		if (current < current->next)
		{
			listint_t *temp = current->next;

			free(current);
			current = temp;
			len++;
		}
		else
		{
			free(current);
			len++;
			break;
		}
	}

	*head = NULL;
	return (len);
}
