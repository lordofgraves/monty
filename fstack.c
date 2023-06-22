#include "monty.h"

/**
 * fstack - free a doubly linked list
 * @head: head of the list
 */
void fstack(stack_t *head)
{
	stack_t *current;
	stack_t *next;
	if (head == NULL)
		return;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
