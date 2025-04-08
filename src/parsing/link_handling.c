/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** handle link operations
*/

#include "lib.h"
#include "my.h"

static int add_room(maze_t *maze, char **tab, int *room_index)
{
    int room_id = 0;

    if (!my_str_isnum(tab[0]) || !my_str_isnum(tab[1]) ||
        !my_str_isnum(tab[2])) {
        return 84;
    }
    print_tab(tab);
    room_id = my_getnbr(tab[0]);
    maze->room->rooms = my_realloc(maze->room->rooms,
        sizeof(int) * (*room_index + 2));
    if (!maze->room->rooms)
        return 84;
    maze->room->rooms[(*room_index)] = room_id;
    (*room_index)++;
    maze->room->rooms[*room_index] = 0;
    return 0;
}

static int add_link(maze_t *maze, char **tab, int *link_index)
{
    if (!my_str_isnum(tab[0]) || !my_str_isnum(tab[1]))
        return 84;
    maze->matrice->tab_link = realloc(maze->matrice->tab_link,
        sizeof(way_t *) * (*link_index + 2));
    if (!maze->matrice->tab_link)
        return 84;
    maze->matrice->tab_link[*link_index] = malloc(sizeof(way_t));
    if (!maze->matrice->tab_link[*link_index])
        return 84;
    maze->matrice->tab_link[*link_index]->first_room = my_getnbr(tab[0]);
    maze->matrice->tab_link[*link_index]->second_room = my_getnbr(tab[1]);
    (*link_index)++;
    maze->matrice->tab_link[*link_index] = NULL;
    return 0;
}

static int process_room(maze_t *maze, char *line, int *room_index)
{
    char **tab = my_str_to_word_array(line);
    int result = 84;

    if (tab && tab[0] && tab[1] && tab[2] && !tab[3]) {
        result = add_room(maze, tab, room_index);
    }
    my_free_word_array(tab);
    return result;
}

static int process_link(maze_t *maze, char *line, int *link_index)
{
    char **tab = my_strtok_array(line, "-");
    int result = 84;

    if (tab && tab[0] && tab[1] && !tab[2]) {
        result = add_link(maze, tab, link_index);
    }
    my_free_word_array(tab);
    return result;
}

int new_room(maze_t *maze, FILE *file, char *line)
{
    static int room_index = 0;
    static int link_index = 0;

    if (!maze || !maze->room)
        return 84;
    if (line[0] == '#' && strncmp(line, "##", 2) != 0)
        return 0;
    if (process_room(maze, line, &room_index) == 0)
        return 0;
    if (process_link(maze, line, &link_index) == 0)
        return 0;
    return 84;
}
