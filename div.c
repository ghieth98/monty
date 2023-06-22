#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the file
 */

void _div(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*stack)->next->n /= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
