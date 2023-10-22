#include "monty.h"

/**
 * print_usage_error - .
 */
void print_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * print_open_file_error - .
 * @file_name: ..
 */
void print_open_file_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
/**
 * print_invalid_instruction_error - Prints an error message and exits when
 * an unrecognized opcode is encountered
 * @line_number: Line number of the current operation
 * @opcode_instruction: Pointer to the unrecognized opcode
 */
void print_invalid_instruction_error(int line_number, char *opcode_instruction)
{

	fprintf(stderr, "L%d: unknown instruction %s\n",
							line_number, opcode_instruction);
	free_everything();
	exit(EXIT_FAILURE);
}
/**
 * print_malloc_error - .
 */
void print_malloc_error(void)
{
	free_everything();
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
