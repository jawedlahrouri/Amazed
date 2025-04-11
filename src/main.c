/*
** EPITECH PROJECT, 2025
** a-maze-d
** File description:
** main file for testing parsing
*/

#include "my.h"
#include "lib.h"

void flag_h(void)
{
    my_printf("USAGE ./amazed file_name\nDESCRIPTION\n"
        "file_name file containing maze description\n");
}

int main(int argc, char **argv)
{
    maze_t *maze = NULL;
    int result = 0;

    (void)argv;
    if (argc > 1) {
        flag_h();
        return 84;
    }
    maze = collect_maze_data();
    if (!maze || !maze->matrice->tab_link || !maze->room->end ||
        !maze->room->start || !maze->room->rooms || maze->nb_robots <= 0)
        return 84;
    maze->matrice = def_matrice(maze->matrice->tab_link,
        maze->matrice->nb_room);
    result = display_parsing(maze);
    cleanup_maze(maze);
    return result;
}
