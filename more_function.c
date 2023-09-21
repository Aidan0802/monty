#include "monty.h"

/**
 * pop_opscode - Removes the top value
 * @line_number: Line number
 * Return: void
 */

void pop_opcode(unsigned int line_number)
{
	stack_t *top = stack;

	if (!stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	stack = top->next;
	if (stack)
		stack->prev = NULL;
	free(top);
}
