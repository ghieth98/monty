#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer tto the top of the stack
 * @line_number: line number of the operation code
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_dlist(stack);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(stack);
}
