/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** queue.c
*/

#include "my.h"

void init_queue(queue_t *queue, int nb_robot)
{
    queue->items = malloc(sizeof(robot_t *) * nb_robot);
    if (queue->items == NULL) {
        perror("malloc failed");
        exit(1);
    }
    queue->first_add = -1;
    queue->last_add = -1;
    queue->nb_robot_max = nb_robot;
}

void enqueue(queue_t *queue, robot_t *robot)
{
    if (queue->last_add == queue->nb_robot_max - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->first_add == -1) {
        queue->first_add = 0;
        queue->last_add = 0;
    } else {
        queue->last_add++;
    }
    queue->items[queue->last_add] = robot;
}

robot_t *dequeue(queue_t *queue)
{
    robot_t *item = malloc(sizeof(robot_t));

    if (queue->first_add == -1 || queue->first_add > queue->last_add)
        return NULL;
    if (item == NULL)
        return NULL;
    item = queue->items[queue->first_add];
    queue->first_add++;
    if (queue->first_add > queue->last_add) {
        queue->first_add = -1;
        queue->last_add = -1;
    }
    return item;
}
