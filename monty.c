#include "monty.h"

my_data_t my_data = {0, NULL, NULL, NULL, NULL, NULL, STACK};
/**
 * main - Entry point for the Monty interpreter program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{

	if (argc != 2)
		print_usage_error();


	return (execute_file(argv[1]));

}
