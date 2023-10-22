#include "monty.h"
/**
 * print_sub_error - Prints an error message and terminates the program
 * if the stack is too short for the "sub" operation.
 * @line_number: Line number of the current operation.
 * Return: Nothing
 */
void print_sub_error(int line_number)
{

	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}


/**
 * is_num - Checks if a string represents a valid integer
 * @num: The string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_num(char *num)
{
	int i = 0;

	if (num[i] == '-')
		i++;

	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0); /* Not a number */
		i++;
	}

	return (1); /* It's a number */
}
