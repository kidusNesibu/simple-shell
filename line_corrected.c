#include "shell.h"
/**
 * line_corrected - takes string retrieved by getline
 * @line: string retrieved from getline
 *
 * Return: corrected_line
 */
char *line_corrected(char *line)
{
	int count_line = 0, i, j = 0;
	char *corrected_line;

	while (line[count_line] != '\0')
		count_line++;
	corrected_line = malloc(sizeof(char) * (count_line + 1));
	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != '\n')
		{
			corrected_line[j++] = line[i];
		}
	}
	corrected_line[j] = '\0';
	return (corrected_line);
}
