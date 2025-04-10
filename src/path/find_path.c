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
    printf("static before incrementation : %i\n", i);
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
    printf("static after incrementation : %i\n", i);
    return node;
}

node_t **get_room_tab(room_t *room, matrice_t *matrice)
{
    // for (int i = 0; room->rooms[i] != NULL; i++) {
    //     printf("id : %s\nis_start : %i\nis_end : %i\nidx : %i\n", room->rooms[i]->id, room->rooms[i]->is_start, room->rooms[i]->is_end, room->rooms[i]->idx);
    // }
    // print_matrice(matrice);
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
    // for (int i = 0; tab[i] != NULL; i++) {
    //     printf("------------------\n");
    //     printf("id : %s\nis_start : %i\nis_end : %i\nidx : %i\n", tab[i]->id, tab[i]->is_start, tab[i]->is_end, tab[i]->idx);
    // }
    return tab;
}

node_t **def_room(room_t *rooms)
{
    int i = 0;
    node_t **node_tab = malloc(sizeof(node_t *) * (rooms->nb_rooms + 1));

    if (!node_tab)
        return NULL;
    for (int y = 0; rooms->rooms[y] != NULL; y++) {
        node_tab[i] = rooms->rooms[y];
        i++;
    }
    node_tab[i] = NULL;
    return node_tab;
}

node_t **get_neighbours(node_t *node, matrice_t *matrice, node_t **tab)
{
    printf("-------------------------loooool------------------\n");
    node_t **neighbours = malloc(sizeof(node_t *) * (matrice->nb_room + 1));
    node_t *new_node = NULL;
    int index = 0;

    if (!neighbours) {
        printf("dans le if de neighbours\n");
        return NULL;
    }
    for (int i = 0; tab[i] != NULL; i++) {
        printf("tab[i] id = %s\n", tab[i]->id);
    }
    for (int i = 0; i < matrice->nb_room; i++) {
        new_node = tab[i];
        printf("new_node id : %s\n", new_node->id);
        printf("node id : %s\n", node->id);
        if (is_connect(node, new_node, matrice) == 0) {
            neighbours[index] = new_node;
            index++;
        }
    }
    printf("%i\n", index);
    neighbours[index] = NULL;
    if (neighbours[0] == NULL)
        printf("bah wsh c une folie ca !\n");
    for (int i = 0; neighbours[i] != NULL; i++) {
        printf("id : %s\ni = %i\n", neighbours[i]->id, i);
    }
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
    printf("---------------------------solve---------------------------\n");
    queue_t *queue = malloc(sizeof(queue_t)); // queue def but already one fill
    if (!queue) {
        printf("dans le premier if de solve\n");
        return NULL;
    }
    if (!rooms || !matrice) {
        printf("dans le seconde if de solve\n");
        return NULL;
    }
    printf("no error in solve\n");
    node_t **node_tab = get_room_tab(rooms, matrice); // bon tab
    init_queue(queue, matrice->nb_room);
    //def_queue(rooms, queue);
    enqueue(queue, start);
    printf("last_in : %s\n first_in : %s\n", queue->last_add, queue->first_add);
    // printf("------------------looooooool-------------------\n");
    // print_queue(queue);
    printf("-----------------------ici c bon---------------------\n");
    //enqueue(queue, start);
    bool *visited = malloc(sizeof(bool) * (rooms->nb_rooms + 1));
    memset(visited, 0, sizeof(bool) * (rooms->nb_rooms + 1));
    node_t **prev = malloc(sizeof(node_t *) * (rooms->nb_rooms + 1));
    memset(prev, 0, sizeof(node_t *) * (rooms->nb_rooms + 1));
    visited[start->idx] = true;
    while (!is_empty(queue)) {
        node_t *node = dequeue(queue);
        if (node) {
            node_t **neighbours = get_neighbours(node, matrice, node_tab);
            
            for (int i = 0; neighbours[i] != NULL; i++) {
                if (!visited[neighbours[i]->idx]) {
                    enqueue(queue, neighbours[i]);
                    visited[neighbours[i]->idx] = true;
                    prev[neighbours[i]->idx] = node;
                }
            }
            free(neighbours);
        }
    }
    free(visited);
    return prev;
}

int bfs(node_t *start, node_t *end, room_t *rooms, matrice_t *matrice)
{
    if (!matrice || !rooms || !start) {
        printf("dans le premier if de bfs\n");
        return 0;
    }
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
