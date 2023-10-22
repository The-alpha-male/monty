#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;
 /**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
FILE *file_fd = NULL;
int exit_code = EXIT_SUCCESS;

if (argc != 2)
{
return (u_sageerror());

}
file_fd = fopen(argv[1], "r");
if (file_fd == NULL)
{
return (f_open_error(argv[1]));
}
exit_code = run_monty(file_fd);
fclose(file_fd);
return (exit_code);
}
