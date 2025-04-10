/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** display parsing
*/

#include "my.h"
#include "lib.h"

static void print_single_room(node_t *room)
{
    my_printf("%s %s %s\n", room->id, room->second_id, room->third_id);
}

static void print_start_room(node_t *start)
{
    my_printf("##start\n");
    print_single_room(start);
}

static void print_end_room(node_t *end)
{
    my_printf("##end\n");
    print_single_room(end);
}

static void print_regular_rooms(maze_t *maze, int index)
{
    for (int j = 0; maze->room->rooms[j] != NULL; j++) {
        if (maze->room->rooms[j]->idx == index) {
            print_single_room(maze->room->rooms[j]);
        }
    }
}

int print_room(maze_t *maze)
{
    if (!maze)
        return 84;
    my_printf("#rooms\n");
    for (int i = 0; i < maze->room->nb_rooms; i++) {
        if (maze->room->start->idx == i)
            print_start_room(maze->room->start);
        if (maze->room->end->idx == i)
            print_end_room(maze->room->end);
        else
            print_regular_rooms(maze, i);
    }
    return 0;
}

int print_links(maze_t *maze)
{
    if (!maze || !maze->matrice->tab_link)
        return 84;
    my_printf("#tunnels\n");
    for (int i = 0; maze->matrice->tab_link[i] != NULL; i++) {
        my_printf("%s-%s\n", maze->matrice->tab_link[i]->first_room,
            maze->matrice->tab_link[i]->second_room);
    }
    return 0;
}

int display_parsing(maze_t *maze)
{
    my_printf("#number_of_robots\n%d\n", maze->nb_robots);
    if (print_room(maze) == 84)
        return 84;
    if (print_links(maze) == 84)
        return 84;
    return 0;
}
