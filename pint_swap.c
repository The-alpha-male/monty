#include "monty.h"

/**
 * pint - Prints the value of the top element in the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_pint_error(line_number);

	printf("%d\n", (*stack)->n);
}
/**
 * print_pint_error - Prints an error
 * message and terminates the program
 * @line_number: Line number of the current operation
 */
void print_pint_error(int line_number)
{

	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * swap - Swaps the positions of the top two elements in the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (stack == NULL || *stack == NULL)
		print_swap_error(line_number);

	if ((*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
		print_swap_error(line_number);
}
/**
 * print_swap_error - Prints an error
 * message and terminates the program
 * @line_number: Line number of the current operation
 */
void print_swap_error(int line_number)
{

	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
