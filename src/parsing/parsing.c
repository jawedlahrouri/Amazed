/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** parse file
*/

#include "my.h"
#include "lib.h"

static void calculate_max_room(maze_t *maze)
{
    int max_room_id = 0;

    if (!maze->room->rooms)
        return;
    for (int i = 0; maze->room->rooms[i] != NULL; i++)
        max_room_id += 1;
    maze->room->nb_rooms = max_room_id + 2;
    maze->matrice->nb_room = maze->room->nb_rooms;
}

static maze_t *process_opened_file(FILE *file)
{
    maze_t *maze = init_maze();

    if (!maze)
        return NULL;
    if (process_first_line(maze, file) == 84) {
        cleanup_maze(maze);
        return NULL;
    }
    if (process_file_lines(maze, file) == 84) {
        cleanup_maze(maze);
        return NULL;
    }
    calculate_max_room(maze);
    return maze;
}

maze_t *collect_maze_data(char *filename)
{
    FILE *file = fopen(filename, "r");
    maze_t *maze = NULL;

    if (!file)
        return NULL;
    maze = process_opened_file(file);
    fclose(file);
    return maze;
}
