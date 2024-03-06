#include "shell.h"
/**
 * custom_setenv - wrapper function for setenv.
 * @ptr2: the token of input passed
 *
 */
void custom_setenv(char **ptr2, char **ptr __attribute__((unused)))
{
	int i, argument_count = 0, overwrite = 1, result;

	for (i = 0; ptr2[i] != NULL; i++)
		argument_count++;
	if (argument_count != 3)
	{
		return;
	}
	if (argument_count == 3)
	{
		result = _setenv(ptr2[1], ptr2[2], overwrite);
		if (result != 0)
			printf("Error setting Environment Variable\n");
	}
}
