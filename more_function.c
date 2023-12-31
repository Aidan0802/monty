#include "monty.h"

/**
 * pop_opcode - Removes the top value
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

/**
 * swap_opcode - Swap top two elements
 * @line_n: Number of lines
 * Return: Void
 */

void swap_opcode(unsigned int line_n)
{
	int temp;

	if (!stack || !stack->next)
	{
		free(stack);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	temp = stack->n;
	stack->n = stack->next->n;
	stack->next->n = temp;
}

/**
 * add_opcode - Adds two top elements
 * @line_n: Line number
 * Return: void
 */

void add_opcode(unsigned int line_n)
{
	int sum = 0;
	stack_t *temp;

	if (!stack || !stack->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	sum = stack->n + stack->next->n;
	temp = stack->next;
	free(stack);
	stack = temp;
	stack->n = sum;
}
