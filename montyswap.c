#include "monty.h"

void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);

/**
 * swap - Swap the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int temp_n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_n;
}

/**
 * add - Add the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*stack = temp->next;
	free(temp);
}

/**
 * nop - Do nothing
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - Subtract the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*stack = temp->next;
	free(temp);
}

/**
 * divi - Divide the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = temp->next->n / temp->n;
	temp->next->n = div;
	*stack = temp->next;
	free(temp);
}


