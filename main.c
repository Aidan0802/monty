#include "monty.h"
/**
 * main - Starting fucntion.
 * @argv: Argument vector
 * @argc: Argument count
 * Return: 0 (Success) EXIT_FAILURE (Fail)
 */
int main(int argc, char *argv[])
{
	FILE *file;
	instruction_t options[] = {
		{"push", push_opcode}, {"pall", pall_opcode}};
	unsigned int line_number = 0, i, found = 0;
	char line[MAX_LINE], *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open_file(argv);
	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (!opcode)
			continue;
		arg = strtok(NULL, " \n");
		for (i = 0; i < sizeof(options) / sizeof(options[0]); i++)
		{
			if (strcmp(opcode, options[i].opcode) == 0)
			{
				options[i].f(&stack, line_number, arg);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			if (stack)
				free_stack(stack);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		found = 0;
	}
	fclose(file), free_stack(stack);
	return (0);
}
