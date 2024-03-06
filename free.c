#include "shell.h"
void free_strtow(char **argv)
{
    int i;

    if (argv != NULL)
    {
        for (i = 0; argv[i] != NULL; i++)
        {
            free(argv[i]);
        }
	free(argv[i]);
        free(argv);
    }
}

