#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *medlyna, *bystra;

	medlyna = head;
	bystra = head;

	while (medlyna && bystra && bystra->next)
	{
		medlyna = medlyna->next;
		bystra = bystra->next->next;
		if (medlyna == bystra)
		{
			medlyna = head;
			break;
		}
	}
	if (!medlyna || !bystra || !bystra->next)
		return (NULL);
	while (medlyna != bystra)
	{
		medlyna = medlyna->next;
		bystra = bystra->next;
	}
	return (bystra);
}
