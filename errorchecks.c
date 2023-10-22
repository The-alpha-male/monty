#include "monty.h"

void error_check(int argc, char *argv[]);
void set_op_tok_error(int error_code);
int u_sageerror(void);
int malloc_error(void);
int f_open_error(char *file);
/*extern global_t global;*/

/**
 * error_check - Check for errors in the arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: void
 */

void error_check(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * set_op_tok_error - Set the error code
 * @error_code: error code
 * Return: void
 */

void set_op_tok_error(int error_code)
{
int tkn_arr_len = 0;
int i = 0;
char *err_msg = NULL;
char **token_arr = NULL;

tkn_arr_len = token_arr_len();
token_arr = malloc(sizeof(char *) * (tkn_arr_len + 2));

if (!op_toks)
{
malloc_error();
return;
}
while (i < tkn_arr_len)
{
token_arr[i] = op_toks[i];
i++;
}
err_msg = go_toint(error_code);
if (!err_msg)
{
free(token_arr);
malloc_error();
return;
}
token_arr[i] = err_msg;
token_arr[i + 1] = NULL;
free(op_toks);
op_toks = token_arr;
}

/**
 * u_sageerror - Usage error
 * Return: EXIT_FAILURE
 */

int u_sageerror(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
 * malloc_error - Malloc error
 * Return: EXIT_FAILURE
 */

int malloc_error(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}

/**
 * f_open_error - File open error
 * @file: file
 * Return: EXIT_FAILURE
 */

int f_open_error(char *file)
{
fprintf(stderr, "Error: Can't open file %s\n", file);
return (EXIT_FAILURE);
}
