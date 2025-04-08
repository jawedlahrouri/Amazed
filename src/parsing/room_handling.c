/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** handle room operations
*/

#include "lib.h"
#include "my.h"

static int validate_room_data(char **tab, int *position)
{
    if (!tab || !tab[0] || !tab[1] || !tab[2] || tab[3])
        return 84;
    if (!my_str_isnum(tab[0]) || !my_str_isnum(tab[1]) ||
        !my_str_isnum(tab[2]))
        return 84;
    *position = my_getnbr(tab[0]);
    return 0;
}

static int parse_room_position(FILE *file, int *position)
{
    size_t len = 0;
    ssize_t read;
    char *next_line = NULL;
    char **tab = NULL;
    int result;

    read = getline(&next_line, &len, file);
    if (read == -1 || next_line == NULL)
        return 84;
    tab = my_str_to_word_array(next_line);
    result = validate_room_data(tab, position);
    free(next_line);
    if (tab)
        my_free_word_array(tab);
    return result;
}

int attribute_start(maze_t *maze, FILE *file, char *line)
{
    if (!maze || !file || !line || my_strcmp(line, "##start") != 0)
        return 1;
    return parse_room_position(file, &maze->room->start);
}

int attribute_end(maze_t *maze, FILE *file, char *line)
{
    if (!maze || !file || !line || my_strcmp(line, "##end") != 0)
        return 1;
    return parse_room_position(file, &maze->room->end);
}
