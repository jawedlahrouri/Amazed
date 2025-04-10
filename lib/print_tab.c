/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** print_tab.c
*/

#include "lib.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("line tab = %s\n", tab[i]);
    }
}
