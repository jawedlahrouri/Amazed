/*
** EPITECH PROJECT, 2025
** lib
** File description:
** strtok in an array
*/

#include "lib.h"

char **my_strtok_array(char *str, const char *sep)
{
    char **result = malloc(sizeof(char *) * 100);
    char *token = my_strtok(str, sep);
    int i = 0;

    for (; token != NULL; i++) {
        result[i] = my_strdup(token);
        token = my_strtok(NULL, sep);
    }
    result[i] = NULL;
    return result;
}
