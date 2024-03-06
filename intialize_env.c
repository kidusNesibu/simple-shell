#include "shell.h"
/**
 *
 *
 */
void intialize_env()
{
	extern char **environ, **custom_environment;
	int i, j, count_env = 0, count;
	char *string;

	while (environ[count_env] != NULL)
		count_env++;
	custom_environment = malloc(sizeof(char *) *(count_env + 1));
	if (custom_environment == NULL)
	{
		perror("Failed to allocate custom env");
		exit(EXIT_FAILURE);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		count = 0;
		string = environ[i];
		while (string[count] != '\0')
			count++;
		*(custom_environment + i) = malloc(sizeof(char) * (count + 1));
		if (*(custom_environment + i) == NULL)
		{
			perror("Failed to allocate custom env entry");
			free_strtow(custom_environment);
		}
		for (j = 0; j < count; j++)
		{
			*(*(custom_environment + i) + j) = string[j];
		}
		*(*(custom_environment + i) + j) = '\0';
	}	
	*(custom_environment + i) = NULL;
}
