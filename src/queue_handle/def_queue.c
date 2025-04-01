/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** def_queue.c
*/

#include "my.h"
#include "lib.h"

// function for create the item (node_t) for each room
node_t *get_node(char *id_node, int is_special_node)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->id = my_strdup(id_node);
    node->is_start = 0;
    node->is_end = 0;
    if (is_special_node == 1)
        node->is_start = 1;
    if (is_special_node == 2)
        node->is_end = 1;
    return node;
}

// function for def the queue with all the rooms
void def_queue(room_t *rooms, queue_t *queue)
{
    node_t *node = NULL;

    for (int i = 0; rooms->start[i] != NULL; i++) {
        node = get_node(rooms->start[i], 1);
        enqueue(queue, node);
    }
    for (int i = 0; rooms->rooms[i] != NULL; i++) {
        node = get_node(rooms->rooms[i], 0);
        enqueue(queue, node);
    }
    for (int i = 0; rooms->end[i] != NULL; i++) {
        node = get_node(rooms->end[i], 1);
        enqueue(queue, node);
    }
}
