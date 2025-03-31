/*
** EPITECH PROJECT, 2025
** a-maze-d
** File description:
** main file
*/

#include "my.h"
#include "lib.h"

void flag_h(void)
{
    my_printf("USAGE ./asm file_name[.s]\nDESCRIPTION\n"
        "file_name file in assembly language"
        " to be converted into file_name.cor,"
        " an executable in the Virtual Machine.\n");
}

int main(int argc, char **argv)
{
    if (argc <= 1) {
        return 84;
    }

// test matrice d'adjascence

    way_t link1 = {1, 0};
    way_t link2 = {3, 2};
    way_t link3 = {0, 4};
    way_t link4 = {1, 3};
    way_t *tab[] = {&link1, &link2, &link3, &link4, NULL};
    matrice_t *matrice = def_matrice(tab, 5);
    if (!matrice) {
        return 84;
    }
    print_matrice(matrice);

    // test queue robot

    queue_t queue;
    init_queue(&queue, 10);
    robot_t r1 = {1, 2};
    robot_t r2 = {2, 6};
    robot_t r3 = {3, 1};
    enqueue(&queue, &r1);
    enqueue(&queue, &r2);
    enqueue(&queue, &r3);
    robot_t *r;
    while ((r = dequeue(&queue)) != NULL) {
        printf("Robot %d in room %d\n", r->id, r->room);
    }
    free(queue.items);
    for (int i = 0; i < 5; i++)
        free(matrice->matrice_link[i]);
    free(matrice->matrice_link);
    free(matrice);
    return 0;
}



