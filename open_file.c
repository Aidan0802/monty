#include "monty.h"

/**
 * open_file - Open and check file;
 * @arg: File to be opened
 * Return: Return file
 */

FILE *open_file(char **arg)
{
	FILE *file;

	file = fopen(arg[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Could not open file '%s'\n", arg[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}
