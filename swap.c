#include "monty.h"

/**
 * swap - swap the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the operation code
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	if (tmp->next != NULL)
	{
		(*stack)->next = tmp->next;
		(*stack)->next->prev = *stack;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
}
