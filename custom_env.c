#include "shell.h"
/**
 * custom_env - prints environment using environ
 * @ptr2: the token passed 
 *
 */
void custom_env(char **ptr2 __attribute__((unused)), char **ptr __attribute((unused)))
{
	extern char**custom_environment;
	int i;

	for (i = 0; custom_environment[i] != NULL; i++)
	{
		printf("%s\n", custom_environment[i]);
	}
}
