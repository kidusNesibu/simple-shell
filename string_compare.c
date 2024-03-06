#include "shell.h"
/**
 * _strcmp1 - compares two strings
 * @s1: the string that passed
 * @s2: the second string that is passed
 *
 * Return: 0 if they are equal
 */
int _strcmp1(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
