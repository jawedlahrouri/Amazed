/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** display parsing
*/

#include "my.h"
#include "lib.h"

int print_room(maze_t *maze)
{
    if (!maze)
        return 84;
    my_printf("#rooms\n");
    for (int i = 0; i < maze->room->nb_rooms; i++) {
        if (maze->room->start->idx == i) {
            my_printf("##start\n%s %s %s",maze->room->start->id,
                maze->room->start->second_id, maze->room->start->third_id);
        } else if (maze->room->end->idx == i) {
            my_printf("##end\n%s %s %s\n",maze->room->end->id,
                maze->room->end->second_id, maze->room->end->third_id);
        }
        for (int j = 0; maze->room->rooms[j] != NULL; j++) {
            if (maze->room->rooms[j]->idx == i) {
                my_printf("%s %s %s\n", maze->room->rooms[j]->id,
                maze->room->rooms[j]->second_id,
                maze->room->rooms[j]->third_id);
            }
        }
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