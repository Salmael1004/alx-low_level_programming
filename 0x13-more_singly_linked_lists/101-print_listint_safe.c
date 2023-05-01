#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp = NULL;
	const listint_t *link = NULL;
	size_t count = 0;
	size_t new;

	temp = head;
	while (temp)
	{
		printf("[%p] %d\n", (void *)temp, temp->n);
		count++;
		temp = temp->next;
		link = head;
		new = 0;

		while (new < count)
		{
			if (temp == link)
			{
				printf("-> [%p] %d\n", (void *)temp, temp->n);
				return (count);
			}
			link = link->next;
			new++;
		}
		if (!head)
			exit(98);
	}
	return (count);
}
