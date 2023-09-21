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
	unsigned int line_number = 0, i;
	char line[MAX_LINE], *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <monty_script>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (argv[1] == NULL)
	{
		fprintf(stderr, "Usage: %s <monty_script>\n", argv[0]);
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
				break;
			}
		}
	}
	fclose(file), free_stack(stack);
	return (0);
}
