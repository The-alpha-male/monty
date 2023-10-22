#include "monty.h"

void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

/**
 * mul - Multiply the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	mul = temp->n * temp->next->n;
	temp->next->n = mul;
	*stack = temp->next;
	free(temp);
}

/**
 * mod - Modulo the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = temp->next->n % temp->n;
	temp->next->n = mod;
	*stack = temp->next;
	free(temp);
}

/**
 * pchar - Print the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
 * pstr - Print the string starting at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;
	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotate the stack to the top
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n;
	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	n = temp->n;
	while (temp->next != NULL)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}
	temp->n = n;
}
