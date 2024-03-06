#include "shell.h"
/**
 * custom_exit - exits the terminal
 * @ptr2: the stdin passed as pointer to a pointer
 *
 */
void custom_exit(char **ptr2 __attribute__((unused)), char **ptr)
{
	extern char **custom_environment;

	free_strtow(custom_environment);
	free_strtow(ptr2);
	free_strtow(ptr);
	exit(2);
}
