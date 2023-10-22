#include "monty.h"
#include <string.h>

int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void token_free(void);
unsigned int token_arr_len(void);
int run_monty(FILE *file_fd);

/**
 * init_stack - Initialize the stack
 * @stack: pointer to stack
 * Return: void
 */

int init_stack(stack_t **stack)
{
stack_t *str;

str = malloc(sizeof(stack_t));
if (str == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
str->next = NULL;
str->prev = NULL;
*stack = str;
return (EXIT_SUCCESS);
}

/**
 * check_mode - Check if the mode is stack or queue
 * @stack: pointer to stack
 * Return: 0 if stack, 1 if queue
 */

int check_mode(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (2);
}
/**
 * token_free - Free the token array
 * Return: void
 */

void token_free(void)
{
size_t i = 0;

if (op_toks == NULL)
return;

for (i = 0; op_toks[i]; i++)
free(op_toks[i]);

free(op_toks);
}

/**
 * token_arr_len - Get the length of the token array
 * Return: length of token array
 */

unsigned int token_arr_len(void)
{
unsigned int i = 0;

while (op_toks[i])
i++;
return (i);
}

/**
 * run_monty - Run the monty interpreter
 * @file_fd: file descriptor
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int run_monty(FILE *file_fd)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0, exit_status = EXIT_SUCCESS;
unsigned int line_number = 0, prev_tok_len = 0;
void (*op_func)(stack_t**, unsigned int);

if (init_stack(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);

while (fgets(line, len, file_fd))
{
line_number++;
op_toks = strtow(line, DELIMS);
if (op_toks == NULL)
{
if (line_empty(line, DELIMS))
continue;
free_stack(&stack);
return (malloc_error());
}
else if (op_toks[0][0] == '#') /* comment line */
{
token_free();
continue;
}
op_func = get_op(op_toks[0]);
if (op_func == NULL)
{
free_stack(&stack);
exit_status = unknown_op_error(op_toks[0], line_number);
token_free();
break;
}
prev_tok_len = token_arr_len();
op_func(&stack, line_number);
if (token_arr_len() != prev_tok_len)
{
if (op_toks && op_toks[prev_tok_len])
exit_status = atoi(op_toks[prev_tok_len]);
else
exit_status = EXIT_FAILURE;
token_free();
break;
}
token_free();
}
free_stack(&stack);

if (line && *line == 0)
{
free(line);
return (malloc_error());
}

free(line);
return (exit_status);
}
