#include "shell.h"
/**
 * _getline - getline custom simple function
 * @lineptr: pointer to a pointer
 * @n: the size of the string passed
 * @stream: the stdin
 *
 * Return: number of character counted
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	ssize_t result, count = 0;
	char *tmp;

	size_t i = 0;
	*n = 1024;
	
	tmp = malloc(sizeof(char) * (*n));
	if (tmp == NULL)
		return (-1);
	while (1)
	{
		ch = fgetc(stream);
		if (i >= (*n) - 1)
		{
			*n = *n * 2;
			tmp = realloc(tmp,*n);
			if (tmp == NULL)
				return (-1);
		}
		if (ch == EOF || ch == '\n')
			return (-1);
		tmp[i++] = (char)ch;
	}
	tmp[i] = '\0';
	while (tmp[count] != '\0')
		count++;
	*lineptr = malloc(sizeof(char) * (count + 1));
	for (i = 0; tmp[i] != '\0'; i++)
	{
		*(*(lineptr) + i) = tmp[i];
	}
	*(*(lineptr) + i) = '\0';
	free(tmp);
	result = count;
	return (result);
}
