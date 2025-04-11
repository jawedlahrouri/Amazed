/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** print_robot.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "lib.h"

static int get_path_len(node_t **path)
{
    int len = 0;

    while (path[len] != NULL)
        len++;
    return len;
}

static void print_move(int robot_id, node_t *node, int *first)
{
    if (!(*first))
        my_printf(" ");
    my_printf("P%d-%d", robot_id, node->idx);
    *first = 0;
}

static void print_lap_moves(node_t **path, int lap, int nb_robot, int path_len)
{
    int first = 1;
    int pos = 0;

    for (int r = 0; r < nb_robot; r++) {
        pos = lap - r;
        if (pos < 0 || pos >= path_len)
            continue;
        print_move(r + 1, path[pos], &first);
    }
    if (!first)
        my_printf("\n");
}

void print_path(node_t **path, int nb_robot)
{
    int path_len = 0;
    int max_laps = 0;

    if (path[0] == NULL)
        return;
    my_printf("#moves\n");
    path_len = get_path_len(path);
    max_laps = path_len + nb_robot - 1;
    for (int lap = 0; lap < max_laps; lap++)
        print_lap_moves(path, lap, nb_robot, path_len);
}
