/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** room handling for maze parsing
*/

#include "my.h"
#include "lib.h"

static int add_room(maze_t *maze, char **tab, int idx)
{
    static int i = 0;
    node_t *new_room;

    if (init_room_array(maze) == 84)
        return 84;
    new_room = create_node(tab[0], tab[1], tab[2], idx);
    if (!new_room)
        return 84;
    maze->room->rooms = my_realloc(maze->room->rooms,
        sizeof(node_t *) * (i + 2));
    if (!maze->room->rooms) {
        free_node(new_room);
        return 84;
    }
    maze->room->rooms[i] = new_room;
    maze->room->rooms[i + 1] = NULL;
    i++;
    return 0;
}

static int process_room(maze_t *maze, char *line, int idx)
{
    char **tab = my_str_to_word_array(line);
    int result = 84;

    if (tab && tab[0] && tab[1] && tab[2] && !tab[3])
        result = add_room(maze, tab, idx);
    if (tab)
        my_free_word_array(tab);
    return result;
}

static int add_link(maze_t *maze, char **tab, int *link_index)
{
    way_t *new_link;

    if (!maze->matrice->tab_link) {
        maze->matrice->tab_link = malloc(sizeof(way_t *));
        if (!maze->matrice->tab_link)
            return 84;
        maze->matrice->tab_link[0] = NULL;
    }
    maze->matrice->tab_link = my_realloc(maze->matrice->tab_link,
        sizeof(way_t *) * (*link_index + 2));
    if (!maze->matrice->tab_link)
        return 84;
    new_link = create_way(tab[0], tab[1]);
    if (!new_link)
        return 84;
    maze->matrice->tab_link[*link_index] = new_link;
    maze->matrice->tab_link[*link_index + 1] = NULL;
    (*link_index)++;
    return 0;
}

static int process_link(maze_t *maze, char *line, int *link_index)
{
    char **tab = my_strtok_array(line, "-");
    int result = 84;

    if (tab && tab[0] && tab[1] && !tab[2])
        result = add_link(maze, tab, link_index);
    if (tab)
        my_free_word_array(tab);
    return result;
}

int new_room(maze_t *maze, char *line, int idx)
{
    static int link_index = 0;

    if (!maze || !maze->room)
        return 84;
    if (line[0] == '#' && my_strncmp(line, "##", 2) != 0)
        return 0;
    if (my_strchr(line, ' ') && process_room(maze, line, idx) == 0)
        return 0;
    if (my_strchr(line, '-') && process_link(maze, line, &link_index) == 0)
        return 0;
    return 84;
}

static char **read_room_line(FILE *file)
{
    size_t len = 0;
    char *next_line = NULL;
    char **tab = NULL;
    ssize_t read = getline(&next_line, &len, file);

    if (read == -1 || next_line == NULL) {
        if (next_line)
            free(next_line);
        return NULL;
    }
    if (read > 0 && next_line[read - 1] == '\n')
        next_line[read - 1] = '\0';
    tab = my_str_to_word_array(next_line);
    free(next_line);
    if (!tab || !tab[0] || !tab[1] || !tab[2] || tab[3]) {
        my_free_word_array(tab);
        return NULL;
    }
    return tab;
}

static node_t *parse_room_position(FILE *file)
{
    char **tab = read_room_line(file);
    node_t *room = NULL;

    if (!tab)
        return NULL;
    room = create_node(tab[0], tab[1], tab[2], 0);
    my_free_word_array(tab);
    return room;
}

node_t *attribute_start(FILE *file, char *line, int idx)
{
    static int start_count = 0;
    node_t *start = NULL;

    if (!file || !line || my_strcmp(line, "##start") != 0 || start_count == 1)
        return NULL;
    start = parse_room_position(file);
    if (!start)
        return NULL;
    start->is_start = 1;
    start->is_end = 0;
    start->idx = idx;
    start_count++;
    return start;
}

node_t *attribute_end(FILE *file, char *line, int idx)
{
    static int end_count = 0;
    node_t *end = NULL;

    if (!file || !line || my_strcmp(line, "##end") != 0 || end_count == 1)
        return NULL;
    end = parse_room_position(file);
    if (!end)
        return NULL;
    end->is_end = 1;
    end->is_start = 0;
    end->idx = idx;
    end_count++;
    return end;
}

int find_room_type(maze_t *maze, char *line, FILE *file, int idx)
{
    if (!maze || !line || !file)
        return 84;
    while (*line && (*line == ' ' || *line == '\t' || *line == '\n'))
        line++;
    if (*line == '\0')
        return 0;
    if (my_strcmp(line, "##start") == 0) {
        maze->room->start = attribute_start(file, line, idx);
        if (maze->room->start != NULL)
            return 0;
    }
    if (my_strcmp(line, "##end") == 0) {
        maze->room->end = attribute_end(file, line, idx);
        if (maze->room->end != NULL)
            return 0;
    }
    if (new_room(maze, line, idx) == 84)
        return 84;
    return 0;
}
