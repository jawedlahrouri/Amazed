/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** open the file for extract data
*/

#include "lib.h"
#include "my.h"

static int process_file_lines(maze_t *maze, FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, file);
    for (; read != -1; read = getline(&line, &len, file)) {
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';
        if (find_room_type(maze, line, file) == 84) {
            free(line);
            return 84;
        }
    }
    free(line);
    return 0;
}

static void calculate_max_room(maze_t *maze)
{
    int max_room_id = 0;

    for (int i = 0; maze->room->rooms && maze->room->rooms[i] != 0; i++) {
        if (maze->room->rooms[i] > max_room_id)
            max_room_id = maze->room->rooms[i];
    }
    maze->matrice->nb_room = max_room_id + 1;
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
