/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** node utilities for maze parsing
*/

#include "my.h"
#include "lib.h"

void free_node(node_t *node)
{
    if (!node)
        return;
    if (node->id)
        free(node->id);
    if (node->second_id)
        free(node->second_id);
    if (node->third_id)
        free(node->third_id);
    free(node);
}

node_t *create_node(char *id, char *second_id, char *third_id, int idx)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->id = my_strdup(id);
    node->second_id = my_strdup(second_id);
    node->third_id = my_strdup(third_id);
    node->is_start = 0;
    node->is_end = 0;
    node->idx = idx;
    if (!node->id || !node->second_id || !node->third_id) {
        free_node(node);
        return NULL;
    }
    return node;
}

way_t *create_way(char *first, char *second)
{
    way_t *way = malloc(sizeof(way_t));

    if (!way)
        return NULL;
    way->first_room = my_strdup(first);
    way->second_room = my_strdup(second);
    if (!way->first_room || !way->second_room) {
        if (way->first_room)
            free(way->first_room);
        if (way->second_room)
            free(way->second_room);
        free(way);
        return NULL;
    }
    return way;
}

void free_way(way_t *way)
{
    if (!way)
        return;
    if (way->first_room)
        free(way->first_room);
    if (way->second_room)
        free(way->second_room);
    free(way);
}
