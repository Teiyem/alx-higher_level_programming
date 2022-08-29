#include "lists.h"

/**
 * is_palindrome - Function prototype
 * Description: Checks if if a linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (1);

	return (_is_palindrome(head, *head));
}

/**
* _is_palindrome - Function prototype
 * Description: Computes if a linked list is a palindrome
 * @head: Pointer to the head of the list
 * @last: The last node in the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int _is_palindrome(listint_t **head, listint_t *last)
{
	if (last == NULL)
		return (1);

	if (_is_palindrome(head, last->next) && (*head)->n == last->n)
	{
		*head = (*head)->next;
		return (1);
	}

	return (0);
}
