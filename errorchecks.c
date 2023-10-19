#include "monty.h"

void error_check(int argc, char *argv[]);

/**
 * error_check - Check for errors in the arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */

void error_check(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

