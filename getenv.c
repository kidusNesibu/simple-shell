#include "shell.h"
/**
 * _getenv - gets environment variable
 * @name: variable we want to search
 *
 * Return: pointer to the string
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	int value;
	for (i = 0; *(environ + i) != NULL; i++)
	{
		value = _strcmp(environ[i], name);
		if (value == 0)
		{
			return (environ[i]);
		}	
	}
	return (NULL);

}
