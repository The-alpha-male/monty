#include "monty.h"

/**
 * pall - Prints all elements in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}
/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (my_data.arg2)
	{
		if (is_num(my_data.arg2))
		{
			num = atoi(my_data.arg2);
			if (my_data.mode == STACK)
				add_dnodeint(stack, num);
			else
				add_stackint_end(stack, num);
		}
		else
			print_push_error(line_number);

	}
	else
		print_push_error(line_number);
}
/**
 * print_push_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 */
void print_push_error(int line_number)
{

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
/**
 * free_everything - .
 */
void free_everything(void)
{
	free_stack(my_data.stack);
	fclose(my_data.file);
	free(my_data.line);
}
