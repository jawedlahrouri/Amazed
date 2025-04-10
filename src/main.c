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

    if (argc <= 1) {
        flag_h();
        return 84;
    }
    maze = collect_maze_data(argv[1]);
    if (!maze)
        return 84;
    if (display_parsing(maze) == 84)
        return 84;
    cleanup_maze(maze);
    return 0;
}
