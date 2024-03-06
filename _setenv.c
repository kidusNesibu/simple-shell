#include "shell.h"
/**
 * concatenator - concatenates and creates a new enviro
 * @environ: the environment variable passed
 * @environ2: the new environment variable
 * @combined: the new name of variable along with the value passed
 * @count_environ: the number of pointer arrays passed
 * @tracker: the index of the envirnomnet to be overwritten
 *
 */
void concatenator(char **custom_environment, char **environ2, char *combined, int tracker)
{
	char *string;
	int i, j, count;
	
	for (i = 0; custom_environment[i] != NULL; i++)
	{
		count = 0;
		if (tracker == i)
		{
			string = combined;
		}
		else
		{
			string = custom_environment[i];
		}
		while (string[count] != '\0')
			count++;
		*(environ2 + i) = malloc(sizeof(char) * (count + 1));
		if (environ2[i] == NULL)
		{
			free_strtow(environ2);
			perror("malloc failed for environ2 element");
			return;
		}
		for (j = 0; j < count; j++)
		{
			*(*(environ2 + i) + j) = string[j];
		}
		*(*(environ2 + i) + j) = '\0';
	}
	if (tracker == -1)
	{
		count = 0;
		while(combined[count] != '\0')
			count++;
		*(environ2 + i) = malloc(sizeof(char) * (count + 1));
		if (*(environ2 + i) == NULL)
		{
			free_strtow(environ2);
			perror("malloc failed for environ2 element");
			return;
		}
		for (j = 0; j < count; j++)
		{
			*(*(environ2 + i) + j) = combined[j];
		}
		*(*(environ2 + i) + j) = '\0';
		i++;
	}
	*(environ2 + i) = NULL;
}
/**
 * _setenv - sets an environment variable
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: determines whether to overwrite or not
 *
 * Return: 0 on Success
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	/**
	extern char **custom_environment;
	**/
	char **environ2;
	char *combined;
	int valued;
	int i, j, count_environ = 0, count_name = 0, count_value = 0, tracker = -1, combined_size;
	
	while (custom_environment[count_environ] != NULL)
		count_environ++;
	while (name[count_name] != '\0')
		count_name++;
	while (value[count_value] != '\0')
		count_value++;
	combined_size = count_name + count_value + 1;
	combined = malloc(sizeof(char) * (combined_size + 1));
	if (combined == NULL)
		return (-1);
	for (i = 0; name[i] != '\0'; i++)
	{
		combined[i] = name[i];
	}
	combined[i] = '=';
	i++;
	for (j = 0; value[j] != '\0'; j++)
	{
		combined[i] = value[j];
		i++;
	}
	combined[i] = '\0';
	for (i = 0; *(custom_environment + i) != NULL; i++)
	{
		valued = _strcmp(custom_environment[i], name);
		if ((valued == 0 && overwrite != 0) || valued != 0)
		{
			if (valued == 0)
				tracker = i;
			if (valued != 0)
				count_environ++;
			environ2 = malloc(sizeof(char *) * (count_environ + 1));
			if (environ2 == NULL)
			{
				perror("malloc failed for environ2");
				free(combined);
			}
			concatenator(custom_environment, environ2, combined, tracker);
			free_strtow(custom_environment);
			custom_environment = NULL;
			custom_environment = environ2;
			environ2 = NULL;
			break;
		}
		else if (valued == 0)
			continue;
	}
	free(combined);
	return (0);
}
