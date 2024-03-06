#include "shell.h"
/**
 * remover - removes a variable
 * @environ: the pointer of environ
 * @environ2: the pointer that will have the copy of environ
 * @tracker: index which the environ will be removed
 *
 * Retrun: Address of environ2
 */
char **remover(char **environ, char **environ2, int tracker)
{
	char *string;
	int i, j, k = 0, count;
	
	for (i = 0; environ[i] != NULL; i++)
	{
		j = 0;
		count = 0;
		if (tracker == i)
		{
			continue;
		}
		else
		{
			string = environ[i];
		}
		while (string[count] != '\0')
			count++;
		*(environ2 + k) = malloc(sizeof(char) * (count + 1));
		if (environ2[k] == NULL)
		{
			free_strtow(environ2);
			return (NULL);
		}
		for (j = 0; j < count; j++)
		{
			*(*(environ2 + k) + j) = string[j];
		}
		*(*(environ2 + k) + j) = '\0';
		k++;
	}
	*(environ2 + k) = NULL;
	return (environ2);
}
/**
 * _unsetenv - deletes a variable from the environment
 * @name: name of the environment you want to delete
 *
 * Return: 0 on Success
 */
int _unsetenv(const char *name)
{
	extern char **custom_environment;
	char **environ2;
	int i, tracker = -1, count_environ = 0, valued = -1;
	
	while (custom_environment[count_environ] != NULL)
		count_environ++;
	for (i = 0; *(custom_environment + i) != NULL; i++)
	{
		valued = _strcmp(custom_environment[i], name);
		if (valued == 0)
		{
			tracker = i;
			environ2 = malloc(sizeof(char *) * count_environ);
			if (environ2 == NULL)
			{	
				free(environ2);
				return (-1);
			}
			environ2 = remover(custom_environment, environ2, tracker);
			for (i = 0; custom_environment[i] != NULL; i++)
			{
				free(custom_environment[i]);
			}
			free(custom_environment);
			custom_environment = NULL;
			custom_environment = environ2;
			environ2 = NULL;
			break;
		}
	}
	return (0);
}
