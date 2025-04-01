/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** find_path.c
*/

#include "my.h"
#include "lib.h"

int bfs(int nb_node, room_t *rooms, matrice_t *matrice, int start, queue_t *queue)
{
    if (!rooms || !matrice || start < 0 || start >= nb_node)
        return -1;
    
    int *visited = calloc(nb_node, sizeof(int));
    int *parent = malloc(sizeof(int) * nb_node);
    if (!visited || !parent) {
        free(queue);
        free(visited);
        free(parent);
        return -1;
    }
    for (int i = 0; i < nb_node; i++)
        parent[i] = -1;
    node_t *start_node = get_node(rooms->start[0], 1);
    enqueue(queue, start_node);
    visited[start] = 1;
    while (get_size_queue(queue) > 0) {
        node_t *current_node = dequeue(queue);
        int current_id = atoi(current_node->id);
        for (int i = 0; i < nb_node; i++) {
            if (matrice->matrice_link[current_id][i] == 1 && !visited[i]) {
                node_t *next_node = get_node(rooms->rooms[i], 0);
                enqueue(queue, next_node);
                visited[i] = 1;
                parent[i] = current_id;
            }
        }
    }
    free(visited);
    free(parent);
    free(queue);
    return 0;
}
