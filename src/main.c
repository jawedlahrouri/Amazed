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

    // // Initialisation des salles
    // room_t *rooms = malloc(sizeof(room_t));
    // if (!rooms)
    //     return 84;

    // // def of rooms struct
    // rooms->rooms = malloc(sizeof(node_t *) * 3);

    // if (!rooms->rooms)
    //     return 84;

    // rooms->start = def_node("0", 1, 0);
    // rooms->rooms[0] = def_node("1", 0, 0);
    // rooms->rooms[1] = def_node("2", 0, 0);
    // rooms->rooms[2] = NULL;
    // rooms->end = def_node("3", 0, 1);
    // rooms->nb_rooms = 4;

    // // def de la struct way_t
    // way_t link1 = {0, 1};
    // way_t link2 = {1, 3};
    // way_t link3 = {2, 3};
    // way_t *tab[] = {&link1, &link2, &link3, NULL};

    // matrice_t *matrice = def_matrice(tab, rooms->nb_rooms);
    // if (!matrice) {
    //     free(rooms);
    //     return 84;
    // }

    // print_matrice(matrice);
    // // ------------------------------ bon ----------------------------
    // // Création de la file pour BFS
    // queue_t *queue = malloc(sizeof(queue_t));
    // if (!queue) {
    //     free_matrice(matrice, rooms->nb_rooms);
    //     free(rooms);
    //     return 84;
    // }

    // init_queue(queue, rooms->nb_rooms);
    // def_queue(rooms, queue);
    // // print_queue(queue); // issue here 
    // if (!queue) {
    //     printf("lol la queue est vide comme l'air\n");
    // }
    // if (queue)
    //     printf("la ya mais bon\n");
    // print_queue(queue);
    // int found = bfs(rooms->start, rooms->end, rooms, matrice);
    // if (found)
    //     printf("Chemin trouvé !\n");
    // else
    //     printf("Aucun chemin trouvé.\n");
    // free(queue->items);
    // free(queue);
    // free_matrice(matrice, rooms->nb_rooms);
    // free(rooms->start);
    // free(rooms->rooms);
    // free(rooms->end);
    // free(rooms);
    return 0;
}
