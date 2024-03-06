#include "shell.h"
#include <unistd.h>
char *current_directory(char *command_part)
{
	char cwd[PATH_MAX];
	char *absolute_command;
	
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return (NULL);
	}
	absolute_command = malloc(strlen(cwd) + 1 + strlen(command_part + 2) + 1);
	if (absolute_command == NULL)
	{
		return (NULL);
	}
	strcpy(absolute_command, cwd);
	strcat(absolute_command, "/");
	strcat(absolute_command, command_part + 2);
	return (absolute_command);

}
char *concatenate1(char **absolute_path, char **relative_path, int count)
{
	char *absolute_command1;
	int i;
	absolute_command1 = malloc(sizeof(char) * (PATH_MAX));
	absolute_command1[0] = '\0';
	if (count <= 0)
	{
		absolute_command1 = _strcat(absolute_command1, "/");
	}
	if (count > 0)
	{
		for (i = 0; i < count; i++)
		{
			absolute_command1 = _strcat(absolute_command1, absolute_path[i]);
			absolute_command1 = _strcat(absolute_command1, "/");
		}
	}
	for (i = 0; relative_path[i] != NULL; i++)
	{
		if (_strcmp1(relative_path[i], "..") != 0 && _strcmp1(relative_path[i], ".") != 0)
		{
		       absolute_command1 = _strcat(absolute_command1, relative_path[i]);
		       if (count > 0)
		       {
		       		absolute_command1 = _strcat(absolute_command1, "/");
		       }
		}	
	}
	free_strtow(absolute_path);
	free_strtow(relative_path);
	return (absolute_command1);
}
char *absolute_path(char *command_part)
{
	char cwd[PATH_MAX];
	char **absolute_path, **relative_path;
	int i, count_relative = 0, count_absolute = 0, count, value;
	char *absolute_command;
	
	absolute_command = NULL;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd() error");
		return (NULL);
	}
	absolute_path = strtow_directory(cwd);
	relative_path = strtow_directory(command_part);
	for (i = 0; relative_path[i] != NULL; i++)
	{
		value = _strcmp1(relative_path[i], "..");
		if (value == 0)
			count_relative++;
	}
	for (i = 0; absolute_path[i] != NULL; i++)
	{
		count_absolute++;
	}
	count = count_absolute - count_relative;
	absolute_command = concatenate1(absolute_path, relative_path, count);
	return (absolute_command);
}
/**
 * execute_command - searches for a command and execute it
 * @command_part: the string of the commmand passed
 * @ptr: the pointer to array of path created per directory
 * @ptr2: the token passed
 *
 */
void execute_command(char *command_part, char **ptr, char **ptr2)
{
	char **argv, **envp;
	char *path_part, *appended = NULL;
	struct stat filestat;
	pid_t child1, child2;
	int i, status;

	argv = NULL;
	envp = NULL;
	if (ptr == NULL || ptr[0] == NULL || ptr[0][0] == '\0')
	{
		if (command_part[0] == '/')
		{
			appended = command_part;
			envp = envp1(appended);
			if (stat(appended, &filestat) == 0)
			{
				child2 = fork();
				if (child2 == -1)
				{
					perror("Fork");
				}
				else if (child2 == 0)
				{
					argv = argv1(appended, ptr2);
					envp = envp1(appended);
					execve(argv[0], argv, envp);
					perror("Execve");
					exit(EXIT_FAILURE);
				}
				else
				{
					wait(&status);
					if (argv)
						free_strtow(argv);
					if (envp)
						free_strtow(envp);
				}
			}
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", command_part);
			exit(127);
		}

	}
	else if (!(ptr == NULL || ptr[0] == NULL || ptr[0][0] == '\0'))
	{
		
		for (i = 0; ptr[i] != NULL; i++)
		{
			path_part = ptr[i];
			if (command_part[0] == '/')
			{
				path_part = "";
				appended = command_part;
			}
			else if (strncmp(command_part, "./", 2) == 0)
			{
				appended = current_directory(command_part);
				if (appended == NULL)
				{
					free(appended);
					perror("Memory allocation failed for appended");
				}
			}
			else if ((command_part[0] == '.' && command_part[1] == '/') || (command_part[0] == '.' && command_part[1] == '.'))
			{
				appended = absolute_path(command_part);
				if (appended == NULL)
				{
					free(appended);
					perror("Memory allocation failed for appended");
					break;
				}
			}
			else
			{
				path_part = ptr[i];
				appended = appender(path_part, command_part);
				if (appended == NULL)
				{		free(appended);
					perror("Memory allocation failed for appended");
					break;
				}
			}
			if (stat(appended, &filestat) == 0)
			{
				child1 = fork();
				if (child1 == -1)
				{
					perror("Fork");
					if (command_part[0] != '/')
					{
						free(appended);
						break;
					}
				
				}
				else if (child1 == 0)
				{
					argv = argv1(appended, ptr2);
					envp = envp1(appended);
					if (command_part[0] != '/') 
						free(appended);
					execve(argv[0], argv, envp);
					perror("Execve");
					exit(EXIT_FAILURE);
				}
				else
				{
				
					wait(&status);
					if (argv)
						free_strtow(argv);
					if (envp)
						free_strtow(envp);
					if (command_part[0] != '/')
						free(appended);
					break;
				}
			}
			else
			{
				if (command_part[0] != '/' && appended != command_part)
					free(appended);
			}
			if (ptr[i + 1] == NULL)
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", command_part);

				exit(127);
			}
		}
	}
	else
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", command_part);
		exit(127);
	}
}
