/*
** EPITECH PROJECT, 2025
** a-maze-d
** File description:
** main file
*/

#include "my.h"
#include "lib.h"

void flag_h(void)
{
    my_printf("USAGE ./asm file_name[.s]\nDESCRIPTION\n"
        "file_name file in assembly language"
        " to be converted into file_name.cor,"
        " an executable in the Virtual Machine.\n");
}

link_t *create_link(int data)
{
    link_t *node = malloc(sizeof(link_t *));

    node->data = data;
    node->next = NULL;
}

int main(int argc, char **argv)
{
    if (argc <= 1) {
        my_printf("Usage: ./asm file_name[.s] ....\n");
        return 84;
    }
    return 84;
}
