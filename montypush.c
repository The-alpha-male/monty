#include "monty.h"

void (*get_op(char *s))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/**
 * *get_op - Get opcode
 * * @s: opcode
 * Return: pointer to function
 */
void (*get_op(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
 * push - Push opcode
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *new;
int i;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
set_op_tok_error(malloc_error());
return;
}

if (op_toks[1] == NULL)
{
set_op_tok_error(when_no_interror(line_number));
return;
}

for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
continue;
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{
set_op_tok_error(when_no_interror(line_number));
return;
}
}
new->n = atoi(op_toks[1]);

if (check_mode(*stack) == STACK)
{
tmp = (*stack)->next;
new->prev = *stack;
new->next = tmp;
if (tmp)
tmp->prev = new;
(*stack)->next = new;
}
else
{
tmp = *stack;
while (tmp->next)
tmp = tmp->next;
new->prev = tmp;
new->next = NULL;
tmp->next = new;
}
}

/**
 * pall - Pall opcode
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * pint - Pint opcode
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_err(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * pop - Pop opcode
 * @stack: pointer to stack
 * @line_number: line number
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_err(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
