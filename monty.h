#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

#define MAX_LINE 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)();
} instruction_t;

extern stack_t *stack;

void push_opcode(stack_t **head, unsigned int line_number, const char *arg);
void pall_opcode(stack_t **stack);
void push(stack_t **stack, int value);
FILE *open_file(char **arg);
void free_stack(stack_t *stack);
int instructions(unsigned int line_number, char *arg, char *opcode);
void pint_opcode(unsigned int line_number);
void pop_opcode(unsigned int line_number);
void swap_opcode(unsigned int line_n);
void nop_opcode(void);

#endif
