#include <string.h>
#include <stdlib.h>

char **strtowa(char *str) {
    char **tokens;
    int count = 0, j, i;
    char *token, *str_copy, *tmp;
    const char *delim = " ";
    str_copy = strdup(str);
    if (!str_copy) return NULL;


    tmp = strdup(str_copy);
    if (!tmp) {
        free(str_copy);
        return NULL;
    }
    for (token = strtok(tmp, delim); token != NULL; token = strtok(NULL, delim)) {
        count++;
    }
    free(tmp);

    tokens = malloc(sizeof(char *) * (count + 1));
    if (!tokens) {
        free(str_copy);
        return NULL;
    }

 
    i = 0;
    for (token = strtok(str_copy, delim); token != NULL; token = strtok(NULL, delim)) {
        tokens[i++] = strdup(token);
        if (!tokens[i-1]) {
            for (j = 0; j < i-1; j++) {
                free(tokens[j]);
            }
            free(tokens);
            free(str_copy);
            return NULL;
        }
    }
    tokens[i] = NULL;

    free(str_copy);
    return tokens;
}

