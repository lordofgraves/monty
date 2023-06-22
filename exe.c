#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t *opst = create_opcodes();
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return 0;

	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			fopcodes(opst);
			return 0;
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		fopcodes(opst);
		fstack(*stack);
		exit(EXIT_FAILURE);
	}

	fopcodes(opst);
	return 1;
}

/**
 * create_opcodes - creates the opcode-function pairs
 * Return: pointer to the opcode array
 */
instruction_t *create_opcodes(void)
{
	const int NUM_OPCODES = 2;
	instruction_t *opst = malloc(sizeof(instruction_t) * (NUM_OPCODES + 1));
	if (opst == NULL)
	{
		fprintf(stderr, "Failed to find memory for the opcodes\n");
		exit(EXIT_FAILURE);
	}
	opst[0].opcode = "push";
	opst[0].f = a_push;
	opst[1].opcode = "pall";
	opst[1].f = a_pall;
	opst[NUM_OPCODES].opcode = NULL;
	opst[NUM_OPCODES].f = NULL;

	return opst;
}

/**
 * fopcodes - frees the opcode
 * @opst: pointer to the opcode
 */
void fopcodes(instruction_t *opst)
{
	free(opst);
}
