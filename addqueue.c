#include "monty.h"
/**
 * addqueue - add node to the tail
 * @n: new value 
 * @head: head
 * Return: nth
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *tail;

	if (new_node == NULL)
	{
		printf("Error\n");
		return;
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;

	tail->next = new_node;
	new_node->prev = tail;
}
