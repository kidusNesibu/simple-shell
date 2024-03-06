#include "shell.h"
/**
 * argv1 - creates the argv array of pointers for execve
 * @appended: the string to append
 * @ptr2: the input of user tokenized
 *
 * Return: the address of argv that is created
 */
char **argv1(char *appended, char **ptr2)
{
	char *string;
	int i, j, count = 0, count_token = 0, k;
	char **argv;
	
	for (i = 0; ptr2[i] != NULL; i++)
		count_token++;
	argv = malloc(sizeof(char *) * (count_token + 1));
	if (argv == NULL)
		return (NULL);

	for (i = 0; ptr2[i] != NULL; i++)
	{
		j = 0;
		count = 0;
		if (i == 0)
		{
			string = appended;
		}
		else
		{
			string = ptr2[i];
		}
		while (string[count] != '\0')
			count++;
		*(argv + i) = malloc(sizeof(char) * (count + 1));
		if (!argv[i])
		{
			for (k = 0; k < i; k++)
				free(argv[k]);
			free(argv);
			return (NULL);
		}
		for (j = 0; j < count; j++)
		{
			*(*(argv + i) + j) = string[j];
		}
		*(*(argv + i) + j) = '\0';
	}
	*(argv + i) = NULL;

	return (argv);
}
