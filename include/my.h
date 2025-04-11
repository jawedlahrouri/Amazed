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
    #include <stdbool.h>

    #define MAX_PATH 100
/*Struct*/

typedef struct valid_path {
    int nb_link;
    char **node;
    struct valid_path *next;
} valid_path_t;

typedef struct way {
    int first_room;
    int second_room;
    char *first_name;
    char *second_name;
} way_t;

typedef struct matrice {
    int **matrice_link;
    way_t **tab_link;
    int nb_room;
    int link_count;
    int link_capacity;
} matrice_t;

typedef struct node {
    char *id;
    int is_start;
    int is_end;
    int idx;
    char *second_id;
    char *third_id;
} node_t;

typedef struct room {
    node_t *start;
    node_t **rooms;
    node_t *end;
    int nb_rooms;
    int capacity;
} room_t;

typedef struct robot {
    int id;
    int room;
} robot_t;

typedef struct queue {
    node_t **items;
    char *last_add;
    char *first_add;
    int capacity;
    int size;
} queue_t;

typedef struct maze {
    matrice_t *matrice;
    room_t *room;
    int nb_robots;
} maze_t;

typedef struct bfs_data_s {
    bool *visited;
    node_t **prev;
    node_t **node_tab;
    matrice_t *matrice;
} bfs_data_t;

typedef struct bfs_init_s {
    bfs_data_t *bfs_data;
    queue_t **queue;
    room_t *rooms;
    matrice_t *matrice;
    node_t *start;
} bfs_init_t;

typedef struct {
    room_t *rooms;
    matrice_t *matrice;
    int nb_robots;
} graph_t;

/*Function*/

// matrice handling
//void print_matrice(matrice_t *matrice);
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
bool is_empty(queue_t *queue);

//linked list
valid_path_t *add_node(valid_path_t *head, char **tab_node, int nb_link);
void print_list(valid_path_t *head);
valid_path_t *def_linked_list(char **tab_node, int nb_link);
void free_list(valid_path_t *head);

//algorithm
node_t **bfs(node_t *start, node_t *end, graph_t *graph);
int is_connect(node_t *node1, node_t *node2, matrice_t *matrice);
node_t *def_node(char *id, int is_start, int is_end);
int solve(room_t *rooms, node_t *start, matrice_t *matrice, node_t **prev);
node_t **get_neighbours(node_t *node, matrice_t *matrice, node_t **tab);
node_t **get_room_tab(room_t *room, matrice_t *matrice);
void print_path(node_t **path, int nb_robot);

//parsing
maze_t *collect_maze_data(void);
maze_t *init_maze(void);
int process_first_line(maze_t *maze);
void cleanup_maze(maze_t *maze);
int find_room_type(maze_t *maze, char *line, int idx);
node_t *attribute_start(char *line, int idx);
node_t *attribute_end(char *line, int idx);
int new_room(maze_t *maze, char *line, int idx);
int my_getbot(const char *str);
void free_node(node_t *node);
int process_file_lines(maze_t *maze);
node_t *create_node(char *id, char *second_id, char *third_id, int idx);
way_t *create_way(char *first, char *second);
void free_way(way_t *way);
int init_room_array(maze_t *maze);
int display_parsing(maze_t *maze);

int main(int argc, char **argv);
#endif /* !MY_H_ */
