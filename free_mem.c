#include "monty.h"

/**
 * free_stack - Free's memory that was allocated
 * @stack: Address of the stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
