#include "monty.h"



/**
 * _div - .
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_div_error(line_number);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			print_div_by_zero_error(line_number);
		(*stack)->next->n /= (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_div_error(line_number);

}

/**
 * mul - .
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_mul_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_mul_error(line_number);

}

/**
 * print_mul_error - .
 * @line_number: Line number of the current operation
 */
void print_mul_error(int line_number)
{

	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
/**
 * print_div_error - .
 * @line_number: Line number of the current operation
 */
void print_div_error(int line_number)
{

	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * print_div_by_zero_error - .
 * @line_number: Line number of the current operation
 */
void print_div_by_zero_error(int line_number)
{

	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
