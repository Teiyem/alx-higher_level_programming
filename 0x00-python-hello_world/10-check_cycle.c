#include "lists.h"

/**
 * check_cycle - Function prototype
 * Description: Checks if a singly linked list has a cycle in it
 * @list: The list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *current;

	if (list == NULL)
		return (0);

	current = list->next;

	while (current != NULL)
	{
		if (current == list)
			return (1);

		current = current->next;
	}

	return (0);
}
