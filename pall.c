#include "monty.h"

/**
 * pall - prints all  values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the operation code
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
		return;

	(void) line_number;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
