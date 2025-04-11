/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** process line for parsing
*/

#include "my.h"
#include "lib.h"

int process_file_lines(maze_t *maze)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, stdin);
    int idx = 0;

    for (; read != -1; read = getline(&line, &len, stdin)) {
        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';
        if (line[0] == '\0')
            continue;
        if (find_room_type(maze, line, idx) == 84) {
            free(line);
            return 84;
        }
        idx++;
    }
    free(line);
    return 0;
}

int process_first_line(maze_t *maze)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1 || line == NULL) {
        if (line)
            free(line);
        return 84;
    }
    if (read > 0 && line[read - 1] == '\n')
        line[read - 1] = '\0';
    if (line && line[0] != '\0' && my_str_isnum(line)) {
        maze->nb_robots = my_atoi(line);
        free(line);
        return 0;
    }
    free(line);
    return 84;
}
