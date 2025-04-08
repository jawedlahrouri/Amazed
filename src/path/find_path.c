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
        node->is_end = 1;
    return node;
}

node_t **get_room_tab(room_t *room, matrice_t *matrice)
{
    node_t **tab = malloc(sizeof(node_t *) * (matrice->nb_room + 1));
    int index = 0;

    if (!tab)
        return NULL;
    for (int i = 0; room->start[i] != NULL; i++) {
        tab[index] = def_node(room->start[i], 1, 0);
        index++;
    }
    for (int i = 0; room->rooms[i] != NULL; i++) {
        tab[index] = def_node(room->rooms[i], 0, 0);
        index++;
    }
    for (int i = 0; room->end[i] != NULL; i++) {
        tab[index] = def_node(room->end[i], 0, 1);
        index++;
    }
    tab[index] = NULL;
    return tab;
}

node_t **def_room(room_t *rooms)
{
    int i = 0;
    node_t **node_tab = malloc(sizeof(node_t *) * (rooms->nb_rooms + 1));

    if (!node_tab)
        return NULL;
    for (int y = 0; rooms->rooms[y] != NULL; y++) {
        node_tab[i]->id = rooms->rooms[y];
        i++;
    }
    node_tab[i] = NULL;
    return node_tab;
}

node_t **get_neighbours(node_t *node, matrice_t *matrice, node_t **tab)
{
    node_t **neighbours = malloc(sizeof(node_t *) * (matrice->nb_room + 1));
    node_t *new_node = malloc(sizeof(node_t));
    int index = 0;

    if (!neighbours)
        return NULL;
    for (int i = 0; i < matrice->nb_room; i++) {
        new_node = tab[i];
        if (is_connect(node, new_node, matrice)) {
            neighbours[index] = new_node;
            index++;
        }
    }
    neighbours[index] = NULL;
    return neighbours;
}

int reconstruct_path(node_t *start, node_t *end, node_t **prev, node_t **path)
{
    node_t *temp[MAX_PATH];
    int count = 0;

    for (node_t *at = end; at != NULL; at = prev[at->idx]) {
        temp[count++] = at;
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

void print_path(node_t **path)
{
    if (path[0] == NULL) {
        printf("Aucun chemin trouvé.\n");
        return;
    }
    printf("Chemin trouvé : ");
    for (int i = 0; path[i] != NULL; i++) {
        printf("%d ", path[i]->idx);
    }
    printf("\n");
}

node_t **solve(room_t *rooms, node_t *start, matrice_t *matrice)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return NULL;
    if (!rooms || !matrice)
        return NULL;
    node_t **node_tab = get_room_tab(rooms, matrice);
    def_queue(rooms, queue);
    enqueue(queue, start);

    bool *visited = malloc(sizeof(bool) * (rooms->nb_rooms + 1));
    memset(visited, 0, sizeof(bool) * (rooms->nb_rooms + 1));
    
    node_t **prev = malloc(sizeof(node_t *) * (rooms->nb_rooms + 1));
    memset(prev, 0, sizeof(node_t *) * (rooms->nb_rooms + 1));

    visited[start->idx] = true;

    while (!is_empty(queue)) {
        node_t *node = dequeue(queue);
        node_t **neighbours = get_neighbours(node, matrice, node_tab);

        for (int next = 0; neighbours[next] != NULL; next++) {
            if (!visited[neighbours[next]->idx]) {
                enqueue(queue, neighbours[next]);
                visited[neighbours[next]->idx] = true;
                prev[neighbours[next]->idx] = node;
            }
        }
        free(neighbours);
    }
    free(visited);
    return prev;
}

int bfs(node_t *start, node_t *end, room_t *rooms, matrice_t *matrice)
{
    if (!matrice || !rooms || !start)
        return 0;
    node_t **prev = solve(rooms, start, matrice);
    if (!prev)
        return 0;
    print_path(prev);
    node_t **path = malloc(sizeof(node_t *) * (rooms->nb_rooms + 1));
    if (!path) {
        free(prev);
        return 0;
    }
    int path_length = reconstruct_path(start, end, prev, path);
    print_path(path);
    free(prev);
    free(path);
    return path_length;
}

