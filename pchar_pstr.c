#include "monty.h"
/**
 * pchar -  Prints the character representation of the top element in the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL)
		print_pchar_stack_empty_error(line_number);

	num = (*stack)->n;
	if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
		printf("%c\n", num);
	else
		print_pchar_error(line_number);
}
/**
 * pstr - Prints the string representation of the integers in the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 * Return : Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *c;

	UNUSED(line_number);
	c = *stack;
	while (c)
	{
		if ((c->n >= 65 && c->n <= 90) || (c->n >= 97 && c->n <= 122))
		{
			printf("%c", c->n);
			c = c->next;
		}
		else
			break;
	}
	printf("\n");
}

/**
 * print_pchar_error - Prints an error
 * message and terminates the program
 * @line_number: Line number of the current operation
 * Return : Nothing
 */
void print_pchar_error(int line_number)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}

/**
 * print_pchar_stack_empty_error - Prints an error
 * message and terminates the program
 * @line_number: Line number of the current operation
 * Return : Nothing
 */
void print_pchar_stack_empty_error(int line_number)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	free_everything();
	exit(EXIT_FAILURE);
}
