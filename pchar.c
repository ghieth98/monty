#include "monty.h"

/**
 * pchar - print character at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) >= 0 && ((*stack)->n) <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

}
