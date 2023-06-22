#include "monty.h"

/**
 * rotr - rotate so only bottom node of stack becomes first one
 * @stack: node to be rotated
 * @line_number: node number
 */
void rotr(stack_t **stack, unsigned int line_number)
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
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*stack) = (*stack)->prev;
	}
}
