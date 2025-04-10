/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** clean the maze if fail
*/

#include "my.h"
#include "lib.h"

static void cleanup_room(room_t *room)
{
    if (!room)
        return;
    if (room->rooms) {
        for (int i = 0; room->rooms[i] != NULL; i++)
            free_node(room->rooms[i]);
        free(room->rooms);
    }
    free_node(room->start);
    free_node(room->end);
    free(room);
}

static void cleanup_matrice(matrice_t *matrice)
{
    if (!matrice)
        return;
    if (!matrice || !matrice->tab_link)
        return;
    for (int i = 0; matrice->tab_link[i] != NULL; i++)
        free_way(matrice->tab_link[i]);
    free(matrice->tab_link);
    free(matrice);
}

void cleanup_maze(maze_t *maze)
{
    if (!maze)
        return;
    cleanup_room(maze->room);
    cleanup_matrice(maze->matrice);
    free(maze);
}
