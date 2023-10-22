#include "monty.h"
/**
 * sub - Sub
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_sub_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_sub_error(line_number);
}

/**
 * add - .
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_add_error(line_number);

	if ((*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_add_error(line_number);
}

/**
 * mod - .
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_mod_error(line_number);

	if ((*stack)->next)
	{
		if ((*stack)->n == 0)
			print_div_by_zero_error(line_number);
		(*stack)->next->n %= (*stack)->n;
		delete_top_node(stack);
	}
	else
		print_mod_error(line_number);
}

/**
 * print_mod_error - .
 * @line_number: Line number of the current operation
 */
void print_mod_error(int line_number)
{

	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}


/**
 * print_add_error - .
 * @line_number: Line number of the current operation
 */
void print_add_error(int line_number)
{

	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}


