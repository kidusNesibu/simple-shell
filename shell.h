#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

extern char **custom_environment;
typedef struct commands {
	char *command;
	void(*func)(char **ptr2, char **ptr);
} cmd;
char **strtow_path(char *str);
char **strtow(char *str);
int _strcmp(char *s1, const char *s2);
int _strcmp1(char *s1, char *s2);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char **argv1(char *appended, char **ptr2);
void execute_command(char *command_part, char **ptr, char **ptr2);
char *appender(char *path_part, char *command_part);
char **envp1(char *appended);
char *line_corrected(char *line);
void custom_setenv(char **ptr2, char **ptr);
void custom_exit(char **ptr2, char **ptr);
void custom_cd(char **ptr2, char **ptr);
void custom_env(char **ptr2, char **ptr);
void custom_setenv(char **ptr2, char **ptr);
void custom_unsetenv(char **ptr2, char **ptr);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream); 
void free_strtow(char **argv);
char **strtowa(char *str);
char **strtow1(char *str);
char *_strcat(char *dest, char *src);
char **strtow_directory(char *str);
void intialize_env();
#endif
