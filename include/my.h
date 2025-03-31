/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h BOOTCAMP
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdint.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>

/*Struct*/

typedef struct valid_path {
    int nb_link;
    char **node;
    struct valid_path *next;
} valid_path_t;

typedef struct way {
    int first_room;
    int second_room;
} way_t;

typedef struct matrice {
    int **matrice_link;
    way_t **tab_link;
    int nb_room;
} matrice_t;

typedef struct room {
    int *start;
    int *rooms;
    int *end;
} room_t;

typedef struct robot {
    int id;
    int room;
} robot_t;

typedef struct queue {
    robot_t **items;
    int last_add;
    int first_add;
    int nb_robot_max;
} queue_t;

/*Function*/

// matrice handling
void print_matrice(matrice_t *matrice);
matrice_t *def_matrice(way_t **tab, int nb_room);
int fill_matrice(matrice_t *matrice);
void free_matrice(matrice_t *matrice, int nb_room);

// queue handling
void init_queue(queue_t *queue, int nb_robot);
void enqueue(queue_t *queue, robot_t *robot);
robot_t *dequeue(queue_t *queue);

//linked list
valid_path_t *add_node(valid_path_t *head, char **tab_node, int nb_link);
void print_list(valid_path_t *head);
valid_path_t *def_linked_list(char **tab_node, int nb_link);
void free_list(valid_path_t *head);

int main(int argc, char **argv);
#endif /* !MY_H_ */
