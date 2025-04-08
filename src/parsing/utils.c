/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** utils
*/

#include "lib.h"
#include "my.h"

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
    room->start = 0;
    room->end = 0;
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
