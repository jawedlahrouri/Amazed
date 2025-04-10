/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** utilities for maze parsing
*/

#include "my.h"
#include "lib.h"

int init_room_array(maze_t *maze)
{
    if (!maze->room->rooms) {
        maze->room->rooms = malloc(sizeof(node_t *));
        if (!maze->room->rooms)
            return 84;
        maze->room->rooms[0] = NULL;
    }
    return 0;
}

int my_getbot(const char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr * 10 + (str[i] - '0');
        else
            break;
    }
    return nbr;
}

static room_t *init_room(void)
{
    room_t *room = malloc(sizeof(room_t));

    if (!room)
        return NULL;
    room->rooms = NULL;
    room->start = NULL;
    room->end = NULL;
    room->nb_rooms = 0;
    return room;
}

static matrice_t *init_matrice(void)
{
    matrice_t *matrice = malloc(sizeof(matrice_t));

    if (!matrice)
        return NULL;
    matrice->tab_link = NULL;
    matrice->matrice_link = NULL;
    matrice->nb_room = 0;
    return matrice;
}

int is_connect(node_t *node1, node_t *node2, matrice_t *matrice)
{
    if (matrice->matrice_link[node1->idx][node2->idx] == 1)
        return 0;
    else
        return 1;
}

maze_t *init_maze(void)
{
    maze_t *maze = malloc(sizeof(maze_t));

    if (!maze)
        return NULL;
    maze->room = init_room();
    if (!maze->room) {
        free(maze);
        return NULL;
    }
    maze->matrice = init_matrice();
    if (!maze->matrice) {
        free(maze->room);
        free(maze);
        return NULL;
    }
    maze->nb_robots = 0;
    return maze;
}
