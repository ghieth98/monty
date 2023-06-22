#include "monty.h"

/**
 * rotl - rotate so top of stack becomes last one, second becomes first one
 * @stack: node to be rotated
 * @line_number: node number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*stack)->prev = tmp;
		tmp->next = *stack;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		tmp->next->next = NULL;
	}
}
