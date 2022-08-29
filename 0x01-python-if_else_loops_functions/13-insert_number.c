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
	int flag = 0;
	listint_t *node;
	listint_t *current;
	listint_t *after;

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = number, node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (*head);
	}
	current = *head;
	if (number <= current->n)
	{
		node->next = current, *head = node;
		return (*head);
	}
	if (number > current->n && !current->next)
	{
		current->next = node;
		return (node);
	}
	after = current->next;
	while (current)
	{
		if (!after)
			current->next = node, flag = 1;
		else if (after->n == number)
			current->next = node, node->next = after, flag = 1;
		else if (after->n > number && current->n < number)
			current->next = node, node->next = after, flag = 1;
		if (flag)
			break;
		after = after->next, current = current->next;
	}
	return (node);
}
