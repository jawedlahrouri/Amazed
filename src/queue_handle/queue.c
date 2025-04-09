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
    if (!queue) {
        printf("lol pas de queue a print\n");
        return;
    }
    printf("lol dans print queue\n");
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
    queue->items = malloc(sizeof(node_t *) * (nb_node + 1));
    if (!queue->items) {
        return;
    }
    for (int i = 0; i < nb_node + 1; i++)
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
    if (!queue || !queue->first_add || get_size_queue(queue) == 0)
        return NULL;

    for (int i = 0; queue->items[i] != NULL; i++) {
        if (strcmp(queue->items[i]->id, queue->first_add) == 0) {
            node_t *item = queue->items[i];
            if (queue->items[i + 1] != NULL)
                queue->first_add = queue->items[i + 1]->id;
            else
                queue->first_add = NULL;

            return item;
        }
    }

    return NULL;
}
