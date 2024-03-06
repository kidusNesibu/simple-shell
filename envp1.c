#include "shell.h"
/**
 * envp1 - creates the enviornment variable
 * @appended: appended
 *
 * Return: address of created Enviornment
 */
char **envp1(char *appended)
{
	char *envgetter, *string;
	char **envp;
	int count = 0, count_appended = 0, i, j, k;

	
	if (appended == NULL)
		return (NULL);
	envgetter = getenv("HOME");
	if (envgetter == NULL)
	{
		envp = malloc(sizeof(char *));
		envp[0] = NULL;
		return (envp);
	}
	while (appended[count_appended] != '\0')
		count_appended++;
	envp = malloc(sizeof(char *) * 3);
	if (envp == NULL)
		return (NULL);
	for (i = 0; i < 2; i++)
	{
		j = 0;
		count = 0;
		if (i == 0)
		{
			string = appended;
		}
		else if (i == 1)
		{
			string = envgetter;
		}
		while (string[count] != '\0')
		{
			count++;
		}
		*(envp + i) = malloc(sizeof(char) * (count + 1));
		if (!envp[i])
		{
			for (k = 0; k < i; k++)
				free(envp[k]);
			free(envp);
			return (NULL);
		}
		for (j = 0; j < count; j++)
		{
			*(*(envp + i) + j) = string[j];
		}
		*(*(envp + i) + j) = '\0';
	}
	*(envp + i) = NULL;
	return (envp);
}
