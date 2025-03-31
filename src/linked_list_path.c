/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-minishell1-joseph.birck
** File description:
** env.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "my.h"
#include "lib.h"

valid_path_t *add_node(valid_path_t *head, char **tab_node, int nb_link)
{
    valid_path_t *node = malloc(sizeof(valid_path_t));
    valid_path_t *temp;

    if (node == NULL)
        return NULL;
    node->node = tab_node;
    node->nb_link = nb_link;
    node->next = NULL;
    if (!head)
        return node;
    temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
    return head;
}

void print_list(valid_path_t *head)
{
    if (head == NULL)
        return;
    while (head != NULL) {
        for (int i = 0; head->node[i] != NULL; i++)
            my_printf("%s ->", head->node[i]);
        my_printf("%i\n", head->nb_link);
        head = head->next;
    }
}

valid_path_t *def_linked_list(char **tab_node, int nb_link)
{
    valid_path_t *head = NULL;

    head = add_node(head, tab_node, nb_link);
    return head;
}

void free_list(valid_path_t *head)
{
    valid_path_t *temp;

    while (head) {
        temp = head;
        head = head->next;
        for (int i = 0; temp->node[i] != NULL; i++)
            free(temp->node[i]);
        free(temp);
    }
}
