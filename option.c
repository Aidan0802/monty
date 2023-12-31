#include "monty.h"

/**
 * instructions - List of instruction options
 * @line_number: Line number
 * @arg: Argument
 * @opcode: Function to select
 * Return: 0 (found) 1 (not found)
 */

int instructions(unsigned int line_number, char *arg, char *opcode)
{
	unsigned int found = 0, i;

	instruction_t options[] = {
		{"push", push_opcode}, {"pall", pall_opcode}, {"pint", pint_opcode},
		{"pop", pop_opcode}, {"swap", swap_opcode}, {"add", add_opcode},
		{"nop", nop_opcode}
	};

	for (i = 0; i < sizeof(options) / sizeof(options[0]); i++)
	{
		if (strcmp(opcode, options[i].opcode) == 0)
		{
			options[i].f(&stack, line_number, arg);
			found = 1;
			break;
		}
	}

	if (found)
		return (1);
	else
		return (0);
}

/**
 * nop_opcode - Does nothing
 * Return: void
 */

void nop_opcode(void)
{
}
