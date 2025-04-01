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
    char **start;
    char **rooms;
    char **end;
    int nb_rooms;
} room_t;

typedef struct robot {
    int id;
    int room;
} robot_t;

typedef struct node {
    char *id;
    int is_start;
    int is_end;
} node_t;

typedef struct queue {
    node_t **items;
    char *last_add;
    char *first_add;
    int nb_node;
} queue_t;

/*Function*/

// matrice handling
void print_matrice(matrice_t *matrice);
matrice_t *def_matrice(way_t **tab, int nb_room);
int fill_matrice(matrice_t *matrice);
void free_matrice(matrice_t *matrice, int nb_room);

// queue handling
void init_queue(queue_t *queue, int nb_node);
void enqueue(queue_t *queue, node_t *node);
node_t *dequeue(queue_t *queue);
void print_queue(queue_t *queue);
void def_queue(room_t *rooms, queue_t *queue);
node_t *get_node(char *id_node, int is_special_node);
int get_size_queue(queue_t *queue);

//linked list
valid_path_t *add_node(valid_path_t *head, char **tab_node, int nb_link);
void print_list(valid_path_t *head);
valid_path_t *def_linked_list(char **tab_node, int nb_link);
void free_list(valid_path_t *head);

//algorithm
int bfs(int nb_node, room_t *rooms, matrice_t *matrice, int start, queue_t *queue);

int main(int argc, char **argv);
#endif /* !MY_H_ */
