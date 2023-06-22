#include "monty.h"
/**
 * a_push - add node to the top of the stack
 * @head: head
 * @c: number of lines
 * Return: nth
*/
void a_push(stack_t **head, unsigned int c)
{
	int a = 0, b = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == ' ')
			b++;
		for (; bus.arg[b] != '\0'; b++)
		{
			if (bus.arg[b] > 57 || bus.arg[b] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(bus.file);
			free(bus.content);
			fstack(*head);
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(bus.file);
			free(bus.content);
			fstack(*head);
			exit(EXIT_FAILURE);
		}
	a = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, a);
	else
		addqueue(head, a);
	}
}
