#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void free_all(void);

/**
 * rotr - Rotate the bottom element of the stack to the top
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int temp_n;
	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	temp_n = temp->n;
	temp->n = (*stack)->n;
	(*stack)->n = temp_n;
}

/**
 * stack - Set the format of the data to a stack (LIFO)
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.mode = 0;
}

/**
 * queue - Set the format of the data to a queue (FIFO)
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.mode = 1;
}

/**
 * free_stack - Free a stack
 * @stack: pointer to stack
 * Return: void
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * free_all - Free all malloc'd memory
 * Return: void
 */

void free_all(void)
{
	free(global.line);
	fclose(global.file);
	free_stack(global.head);
}

