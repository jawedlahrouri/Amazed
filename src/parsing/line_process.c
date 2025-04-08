/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** process file lines
*/

#include "lib.h"
#include "my.h"

int find_room_type(maze_t *maze, char *line, FILE *file)
{
    if (!maze || !line || !file)
        return 84;
    while (*line && (*line == ' ' || *line == '\t' || *line == '\n'))
        line++;
    if (*line == '\0')
        return 0;
    if (my_strcmp(line, "##start") == 0)
        return attribute_start(maze, file, line);
    if (my_strcmp(line, "##end") == 0)
        return attribute_end(maze, file, line);
    return new_room(maze, file, line);
}

int process_first_line(maze_t *maze, FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, file);
    if (read == -1 || line == NULL) {
        free(line);
        return 84;
    }
    if (line && line[0] != '\0')
        maze->nb_robots = my_getbot(line);
    free(line);
    return 0;
}

void cleanup_maze(maze_t *maze)
{
    if (!maze)
        return;
    if (maze->room && maze->room->rooms)
        free(maze->room->rooms);
    if (maze->matrice && maze->matrice->tab_link) {
        for (int i = 0; maze->matrice->tab_link[i] != NULL; i++)
            free(maze->matrice->tab_link[i]);
        free(maze->matrice->tab_link);
    }
    if (maze->matrice && maze->matrice->matrice_link) {
        for (int i = 0; i < maze->matrice->nb_room; i++)
            free(maze->matrice->matrice_link[i]);
        free(maze->matrice->matrice_link);
    }
    if (maze->matrice)
        free(maze->matrice);
    if (maze->room)
        free(maze->room);
    free(maze);
}
