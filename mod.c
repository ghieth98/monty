#include "monty.h"

/**
 * op_mod - computes the second and first elemnt of the stack
 * @stack: pointer to the top of the stacvk
 * @line_number: line number of the current
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = b % a;
	op_pop(stack, line_number);
}
