#include "monty.h"

/**
 * op_mul - multiplies the second and first element
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
