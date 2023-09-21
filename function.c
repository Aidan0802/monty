#include "monty.h"

stack_t *stack = NULL;

/**
 * push_opcode - Pushes to stack
 * @head: Address of head the stack
 * @line_number: The line number of argument
 * @arg: Argument that is parsed
 * Return: Void
 */

void push_opcode(stack_t **head, unsigned int line_number, const char *arg)
{
	int value, i = 0;

	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (arg[i] != '\0')
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	value = atoi(arg);
	push(head, value);
}

/**
 * pall_opcode - Prints the stack
 * @stack: The address of the stack
 * @line_number: Line argument number
 * Return: void
 */

void pall_opcode(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - Push integer to stack
 * @stack - Address of stack
 * @value: Value to be push on to stack
 * Return: void
 */

void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: Unable to allocate memory for a new node\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (!stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
