#include "monty.h"

/**
 * addnode - add node to the head
 * @head: head
 * @n: new value
 * Return: nth
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }

    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}
