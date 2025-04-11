/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** solve.c
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "lib.h"

static void update_bfs_state(node_t *neighbor, node_t *node, queue_t *queue,
    bfs_data_t *bfs_data)
{
    enqueue(queue, neighbor);
    bfs_data->visited[neighbor->idx] = true;
    bfs_data->prev[neighbor->idx] = node;
}

static void process_neighbours(node_t *node, queue_t *queue,
    bfs_data_t *bfs_data)
{
    node_t **neighbours = NULL;
    int i = 0;

    neighbours = get_neighbours(node, bfs_data->matrice, bfs_data->node_tab);
    for (i = 0; neighbours[i] != NULL; i++) {
        if (!bfs_data->visited[neighbours[i]->idx]) {
            update_bfs_state(neighbours[i], node, queue, bfs_data);
        }
    }
    free(neighbours);
}

static void free_end_bfs(bfs_data_t bfs_data, queue_t *queue)
{
    free(bfs_data.visited);
    free(queue->items);
    free(queue);
}

queue_t *create_queue_for_bfs(node_t *start, int nb_rooms)
{
    queue_t *queue = NULL;

    queue = malloc(sizeof(queue_t));
    if (!queue)
        return NULL;
    init_queue(queue, nb_rooms);
    enqueue(queue, start);
    return queue;
}

bool *init_visited(int nb_rooms, int start_idx)
{
    bool *visited = malloc(sizeof(bool) * nb_rooms);

    if (!visited)
        return NULL;
    for (int i = 0; i < nb_rooms; i++)
        visited[i] = false;
    visited[start_idx] = true;
    return visited;
}

node_t **init_prev(int nb_rooms)
{
    node_t **prev = NULL;

    prev = malloc(sizeof(node_t *) * (nb_rooms + 1));
    if (!prev)
        return NULL;
    my_memset(prev, 0, sizeof(node_t *) * (nb_rooms + 1));
    return prev;
}

static int init_bfs(bfs_init_t args, node_t **prev)
{
    args.bfs_data->node_tab = get_room_tab(args.rooms, args.matrice);
    args.bfs_data->visited =
        init_visited(args.rooms->nb_rooms, args.start->idx);
    args.bfs_data->prev = prev;
    args.bfs_data->matrice = args.matrice;
    *(args.queue) = create_queue_for_bfs(args.start, args.rooms->nb_rooms);
    if (!*(args.queue)) {
        free(args.bfs_data->visited);
        free(args.bfs_data->node_tab);
        return 0;
    }
    return 1;
}

int solve(room_t *rooms, node_t *start, matrice_t *matrice, node_t **prev)
{
    bfs_data_t bfs_data = {0};
    queue_t *queue = NULL;
    bfs_init_t args = {&bfs_data, &queue, rooms, matrice, start};
    node_t *node;

    if (!rooms || !matrice || !start || !prev)
        return 0;
    if (!init_bfs(args, prev))
        return 0;
    while (!is_empty(queue)) {
        node = dequeue(queue);
        if (node)
            process_neighbours(node, queue, &bfs_data);
    }
    free_end_bfs(bfs_data, queue);
    return 1;
}
