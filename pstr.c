#include "monty.h"

/**
 * pstr - prints the string at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while ((tmp != NULL) && (tmp->n != 0) &&
	       (tmp->n >= 0) && (tmp->n <= 127))
	{
		printf("%c", (tmp)->n);
		tmp = tmp->next;
	}
	printf("\n");
}
