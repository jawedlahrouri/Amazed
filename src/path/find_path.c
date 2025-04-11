/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** find_path.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "lib.h"

node_t *def_node(char *id, int is_start, int is_end)
{
    static int i = 0;
    node_t *node = malloc(sizeof(node_t));

    if (!id || !node)
        return NULL;
    node->id = my_strdup(id);
    node->idx = i;
    if (is_start == 1)
        node->is_start = 1;
    else
        node->is_start = 0;
    if (is_end == 1)
        node->is_end = 1;
    else
        node->is_end = 0;
    i++;
    return node;
}

node_t **get_room_tab(room_t *room, matrice_t *matrice)
{
    node_t **tab = malloc(sizeof(node_t *) * (matrice->nb_room + 1));
    int index = 0;

    if (!tab)
        return NULL;
    tab[index] = room->start;
    index++;
    for (int i = 0; room->rooms[i] != NULL; i++) {
        tab[index] = room->rooms[i];
        index++;
    }
    tab[index] = room->end;
    index++;
    tab[index] = NULL;
    return tab;
}

node_t **get_neighbours(node_t *node, matrice_t *matrice, node_t **tab)
{
    node_t **neighbours = malloc(sizeof(node_t *) * (matrice->nb_room + 1));
    node_t *new_node = NULL;
    int index = 0;

    if (!neighbours)
        return NULL;
    for (int i = 0; i < matrice->nb_room; i++) {
        new_node = tab[i];
        if (is_connect(node, new_node, matrice) == 0) {
            neighbours[index] = new_node;
            index++;
        }
    }
    neighbours[index] = NULL;
    return neighbours;
}

static int reconstruct_path(node_t *start, node_t *end, node_t **prev,
    node_t **path)
{
    node_t *temp[MAX_PATH];
    int count = 0;

    for (node_t *at = end; at != NULL; at = prev[at->idx]) {
        temp[count] = at;
        count++;
    }
    if (temp[count - 1] != start) {
        return 0;
    }
    for (int i = 0; i < count; i++) {
        path[i] = temp[count - 1 - i];
    }
    path[count] = NULL;
    return count;
}

node_t **bfs(node_t *start, node_t *end, graph_t *graph)
{
    node_t **path = malloc(sizeof(node_t *) * (graph->rooms->nb_rooms + 1));
    node_t **prev = malloc(sizeof(node_t *) * graph->rooms->nb_rooms);

    if (!graph || !graph->matrice || !graph->rooms ||
        !start || !path || !prev) {
        free(path);
        free(prev);
        return NULL;
    }
    for (int i = 0; i < graph->rooms->nb_rooms; i++) {
        prev[i] = NULL;
    }
    if (!solve(graph->rooms, start, graph->matrice, prev)) {
        free(prev);
        free(path);
        return NULL;
    }
    reconstruct_path(start, end, prev, path);
    free(prev);
    return path;
}
