/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** queue.c
*/

#include <stdbool.h>
#include "my.h"
#include "lib.h"

// get the size of the matrice
int get_size_queue(queue_t *queue)
{
    return (queue ? queue->size : 0);
}

// function for print the queue (file)
void print_queue(queue_t *queue)
{
    if (!queue)
        return;
    for (int i = 0; i < queue->size && queue->items[i] != NULL; i++) {
        my_printf("value : %s\n", queue->items[i]->id);
    }
    if (queue->first_add)
        my_printf("value first add : %s\n", queue->first_add);
    if (queue->last_add)
        my_printf("value last add: %s\n", queue->last_add);
}

// function for init the queue before use it (in main for exemple)
void init_queue(queue_t *queue, int nb_node)
{
    if (!queue || nb_node <= 0)
        return;
    queue->items = malloc(sizeof(node_t *) * (nb_node + 1));
    if (!queue->items)
        return;
    for (int i = 0; i < nb_node + 1; i++)
        queue->items[i] = NULL;
    queue->first_add = NULL;
    queue->last_add = NULL;
    queue->capacity = nb_node;
    queue->size = 0;
}

// function for add an item in the queue (item = node_t)
void enqueue(queue_t *queue, node_t *node)
{
    if (!queue || queue->size >= queue->capacity)
        return;
    queue->items[queue->size] = node;
    queue->last_add = node->id;
    if (!queue->first_add)
        queue->first_add = node->id;
    queue->size++;
}

// function for remove an item from the queue (the first add)
node_t *dequeue(queue_t *queue)
{
    node_t *item = malloc(sizeof(node_t));

    if (!item || !queue || !queue->first_add || queue->size == 0)
        return NULL;
    item = queue->items[0];
    for (int i = 0; i < queue->size - 1; i++)
        queue->items[i] = queue->items[i + 1];
    queue->items[queue->size - 1] = NULL;
    queue->size--;
    if (queue->size > 0)
        queue->first_add = queue->items[0]->id;
    else
        queue->first_add = NULL;
    return item;
}
