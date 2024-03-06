#include "shell.h"
/**
 * custom_cd - calls the chdir function
 * @ptr2: the tokenized input of user passed
 *
 */
void custom_cd(char **ptr2, char **ptr)
{
	int argument_count = 0, i, result;
	const char *dirhome;

	for (i = 0; ptr2[i] != NULL; i++)
	{
		argument_count++;
	}
	if (argument_count > 2)
		perror("cd: too many arguments");
	if (argument_count == 1)
	{
		dirhome = getenv("HOME");
		result = chdir(dirhome);
		if (result == -1)
			perror("cd");
	}
	else if (argument_count == 2)
	{
		result = chdir(ptr2[1]);
		if (result == -1)
		{
			free_strtow(ptr);
			free_strtow(ptr2);
			perror("cd");
		}
	}
}
