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

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        printf("value : %s\n", tab[i]);
    }
}

int main(int argc, char **argv)
{
    if (argc <= 1) {
        return 84;
    }
    int i = 0;

// test matrice d'adjascence

    room_t *rooms = malloc(sizeof(room_t));
    rooms->start = malloc(sizeof(char *)* 30);
    rooms->rooms = malloc(sizeof(char *)* 30);
    rooms->end = malloc(sizeof(char *)* 30);
    rooms->start[0] = "0";
    rooms->start[1] = NULL;
    while (i < 3) {
        rooms->rooms[i] = "str";
        i++;
    }
    rooms->rooms[3] = NULL;
    rooms->end[0] = "3";
    rooms->end[1] = NULL;

    // print_tab(rooms->start);
    // print_tab(rooms->rooms);
    // print_tab(rooms->end);
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

    queue_t *queue = malloc(sizeof(queue_t));
    init_queue(queue, 5);
    def_queue(rooms, queue);
    // printf("value last add: %s\n", queue->last_add);
    // printf("item 0 : %s\n", queue->items[0]->id);
    print_queue(queue);
    node_t *r;
    r = dequeue(queue);
    printf("dequeue node : id : %s, is_start %i, is_end : %i\n", r->id, r->is_start, r->is_end);
    free(queue->items);
    for (int i = 0; i < 5; i++)
        free(matrice->matrice_link[i]);
    free(matrice->matrice_link);
    free(matrice);
    return 0;
}



