#include "monty.h"
#include <string.h>

int pchar_error(unsigned int line_number, char *message);
int unknown_op_error(char *op, unsigned int line_number);
char **strtow(char *str, char *delims);
int line_empty(char *line, char *delims);

/**
 * pchar_error - Error when stack is empty for pchar
 * @line_number: line number
 * @message: error message
 * Return: EXIT_FAILURE
 */

int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Error when opcode is unknown
 * @line_number: line number
 * @op: opcode
 * Return: EXIT_FAILURE
 */

int unknown_op_error(char *op, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * strtow - Split a string into words
 * @str: string to split
 * @delims: delimiters
 * Return: pointer to an array of strings (Success), NULL (Error)
 */

char **strtow(char *str, char *delims)
{
char **array;
int i, len, words = 0;

if (str == NULL || strlen(str) == 0)
return (NULL);
len = strlen(str);
array = malloc(sizeof(char *) * (len + 1));
if (array == NULL)
return (NULL);
for (i = 0; i < len; i++)
{
if (str[i] == delims[0])
str[i] = '\0';
}
for (i = 0; i < len; i++)
{
if (str[i] != '\0' && (str[i - 1] == '\0' || i == 0))
{
array[words] = &str[i];
words++;
}
}
array[words] = NULL;
return (array);
}

/**
 * line_empty - Check if a line is empty
 * @line: line to check
 * @delims: delimiters
 * Return: 1 (empty), 0 (not empty)
 */

int line_empty(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

