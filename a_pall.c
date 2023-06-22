#include "monty.h"
/**
 * a_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void a_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
    return;
    else 
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
