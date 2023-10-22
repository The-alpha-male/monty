#include "monty.h"

int when_no_interror(unsigned int line_number);
int pop_err(unsigned int line_number);
int pint_err(unsigned int line_number);
int short_stack(unsigned int line_number, char *op);
int div_error(unsigned int line_number);

/**
 * when_no_interror - Error when no integer is passed to an opcode
 * @line_number: line number
 * Return: EXIT_FAILURE
 */

int when_no_interror(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pop_err - Error when stack is empty for pop
 * @line_number: line number
 * Return: EXIT_FAILURE
 */

int pop_err(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * pint_err - Error when stack is empty for pint
 * @line_number: line number
 * Return: EXIT_FAILURE
 */

int pint_err(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * short_stack - Error when stack is too short for operation
 * @line_number: line number
 * @op: opcode
 * Return: EXIT_FAILURE
 */

int short_stack(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}

/**
 * div_error - Error when stack is too short for div
 * @line_number: line number
 * Return: EXIT_FAILURE
 */

int div_error(unsigned int line_number)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
return (EXIT_FAILURE);
}
