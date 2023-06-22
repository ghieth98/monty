#include "monty.h"

/**
 * _mod - computes the second and first elemnt of the stack
 * @stack: pointer to the top of the stacvk
 * @line_number: line number of the current
 */

void _mod(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*stack)->next->n %= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
