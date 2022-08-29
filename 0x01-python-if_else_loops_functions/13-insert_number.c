#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Function prototype
 * Description: Inserts a number into a sorted linked list
 * @head: Pointer to a pointer to the first node of a linked list
 * @number: The number to insert
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head;

	listint_t *node = malloc(sizeof(listint_t));

	if (node == NULL)
		return (NULL);

	node->n = number;

	if (*head == NULL)
		*head = node;
	else
	{
		while (current->next != NULL)
		{
			if (current->next->n > number)
				break;

			current = current->next;
		}

		node->next = current->next;
		current->next = node;
	}

	return (node);
}
