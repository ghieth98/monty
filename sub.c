#include "monty.h"

/**
 * _sub - substracts the top element of the stack from the second element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
