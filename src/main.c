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

    // Initialisation des salles
    room_t *rooms = malloc(sizeof(room_t));
    rooms->start = malloc(sizeof(char *) * 30);
    rooms->rooms = malloc(sizeof(char *) * 30);
    rooms->end = malloc(sizeof(char *) * 30);
    rooms->start[0] = "0";
    rooms->start[1] = NULL;
    rooms->rooms[0] = "1";
    rooms->rooms[1] = "2";
    rooms->rooms[2] = NULL;
    rooms->end[0] = "3";
    rooms->end[1] = NULL;

    // Définition des liens (edges)
    way_t link1 = {0, 1};
    way_t link2 = {1, 2};
    way_t link3 = {2, 3};
    way_t *tab[] = {&link1, &link2, &link3, NULL};

    // Création de la matrice d'adjacence
    matrice_t *matrice = def_matrice(tab, 4);
    if (!matrice) {
        return 84;
    }

    print_matrice(matrice);  // Affiche la matrice d'adjacence pour vérification

    // Initialisation de la queue et utilisation de def_queue
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return 84;

    init_queue(queue, 4);
    def_queue(rooms, queue);  // Utilisation de ta fonction pour remplir la queue

    // Exécution de BFS
    int start = 0;  // Noeud de départ
    int found = bfs(4, rooms, matrice, start, queue);

    if (found)
        printf("Chemin trouvé !\n");
    else
        printf("Aucun chemin trouvé.\n");

    // Libération de la mémoire
    free(queue->items);
    free(queue);
    free_matrice(matrice, 4);
    free(rooms->start);
    free(rooms->rooms);
    free(rooms->end);
    free(rooms);

    return 0;
}
