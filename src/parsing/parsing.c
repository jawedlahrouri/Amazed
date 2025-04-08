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

    for (int i = 0; maze->room->rooms[i] != NULL; i++) {
        max_room_id += 1;
    }
    maze->matrice->nb_room = max_room_id + 2;
    printf("nb_room : %i\n", maze->matrice->nb_room);
}

static maze_t *process_opened_file(FILE *file)
{
    printf("dans la fonction process_opened_file 2eme fonction de parse\n");
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
    printf("dans la fonction parsing\n");
    printf("filename: %s\n", filename);
    FILE *file = fopen(filename, "r");
    maze_t *maze = NULL;

    if (!file) {
        printf("lol le file est pas valide\n");
        return NULL;
    }
    maze = process_opened_file(file);
    fclose(file);
    return maze;
}