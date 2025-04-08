/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** queue.c
*/

#include <stdbool.h>
#include "my.h"
#include "lib.h"

// si la queue est vide return true
bool is_empty(queue_t *queue)
{
    return queue->nb_node == 0;
}

// function for print the queue (file)
void print_queue(queue_t *queue)
{
    for (int i = 0; i < queue->nb_node && queue->items[i] != NULL; i++) {
        my_printf("value : %s\n", queue->items[i]->id);
    }
    if (queue->first_add)
        my_printf("value first add : %s\n", queue->first_add);
    if (queue->last_add)
        my_printf("value last add: %s\n", queue->last_add);
}

// function for get the size of the queue (malloc and loop on it)
int get_size_queue(queue_t *queue)
{
    int i = 0;

    if (!queue || !queue->items)
        return 0;
    while (i < queue->nb_node && queue->items[i] != NULL) {
        i++;
    }
    return i;
}

// function for init the queue before use it (in main for exemple)
void init_queue(queue_t *queue, int nb_node)
{
    if (nb_node <= 0) {
        queue->items = NULL;
        queue->nb_node = 0;
        return;
    }
    queue->items = malloc(sizeof(node_t *) * nb_node);
    if (!queue->items) {
        return;
    }
    for (int i = 0; i < nb_node; i++)
        queue->items[i] = NULL;
    queue->first_add = NULL;
    queue->last_add = NULL;
    queue->nb_node = nb_node;
}

// function for add an item in the queue (item = node_t)
void enqueue(queue_t *queue, node_t *node)
{
    int size = get_size_queue(queue);

    if (size >= queue->nb_node) {
        return;
    }
    queue->items[size] = node;
    queue->last_add = node->id;
    if (!queue->first_add) {
        queue->first_add = node->id;
    }
}

// function for remove an item from the queue (the first add)
node_t *dequeue(queue_t *queue)
{
    int size = get_size_queue(queue);
    node_t *item = malloc(sizeof(node_t));

    if (!item)
        return NULL;
    if (!queue->first_add) {
        return NULL;
    }
    if (size == 0)
        return NULL;
    item = queue->items[size - 1];
    queue->items[size - 1] = NULL;
    queue->first_add = (size > 1) ? queue->items[size - 2]->id : NULL;
    return item;
}
