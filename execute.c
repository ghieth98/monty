#include "monty.h"


/**
 * execute_file - reads and execute opeartions from a file
 * @stack: pointer to the top of the stack
 */

void execute_file(stack_t **stack)
{
	char *operation = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	while ((nread = getline(&glob.line, &len, glob.file)) != -1)
	{
		line_number++;
		operation = strtok(glob.line, " /t/r/n/a");
		glob.arg = strtok(NULL, " /n/t");
		if (operation == NULL || *operation == '#')
			continue;
		execute_ops(operation, stack, line_number);
	}
}

/**
 * execute_ops - execute an operation code
 * @operation: opertion code to execute
 * @stack: pointer to the top of the stack
 * @line_number: line number of the code of the operation
 */

void execute_ops(char *operation, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"nop", op_nop},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(operation, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruct %s\n", line_number, operation);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}


