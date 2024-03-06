#include "shell.h"
/**
 * appender - appends arguments passed by user
 * @path_part: handles the path
 * @command_part: handles the command part
 *
 * Return: The address of the appended string
 */
char *appender(char *path_part, char *command_part)
{
	int length = 0, count = 0, j, k;
	char *appended;

	while (path_part[count] != '\0')
		count++;
	while (command_part[length] != '\0')
		length++;
	appended = malloc(sizeof(char) * (count + length + 2));
	if (appended == NULL)
		return (NULL);
	for (j = 0; path_part[j] != '\0'; j++)
	{
		if (path_part[j] != '\n')
			appended[j] = path_part[j];
	}
	k = 0;
	appended[j] = '/';
	j++;
	for (k = 0; command_part[k] != '\0'; k++)
	{
		if (command_part[k] != '\n')
		{
			appended[j] = command_part[k];
			j++;
		}
	}
	appended[j] = '\0';
	return (appended);
}
