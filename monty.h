#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
    int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - represents a set of variables 
 * used to carry values through a program
 * @arg: holds a value.
 * @file: used to interact with a Monty file
 * @content: holds the content of a line.
 * @lifi: indicate a change between 
 * the stack and the queue.
 */
struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
};
extern struct bus_s bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void a_push(stack_t **head, unsigned int number);
void a_pall(stack_t **head, unsigned int number);
void fstack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
instruction_t *create_opcodes(void);
void fopcodes(instruction_t *opst);

#endif
