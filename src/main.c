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

    collect_maze_data(argv[1]);

    // Initialisation des salles
    room_t *rooms = malloc(sizeof(room_t));
    if (!rooms)
        return 84;

    rooms->start = malloc(sizeof(node_t *) * 2);
    rooms->rooms = malloc(sizeof(node_t *) * 3);
    rooms->end = malloc(sizeof(node_t *) * 2);
    if (!rooms->start || !rooms->rooms || !rooms->end)
        return 84;

    rooms->start[0] = "0"; rooms->start[1] = NULL;
    rooms->rooms[0] = "1"; rooms->rooms[1] = "2"; rooms->rooms[2] = NULL;
    rooms->end[0] = "3"; rooms->end[1] = NULL;
    rooms->nb_rooms = 4;  // Mise à jour du nombre de salles

    // Définition des connexions entre les salles (graph)
    way_t link1 = {0, 1};
    way_t link2 = {1, 2};
    way_t link3 = {2, 3};
    way_t *tab[] = {&link1, &link2, &link3, NULL};

    // Création de la matrice d'adjacence
    matrice_t *matrice = def_matrice(tab, rooms->nb_rooms);
    if (!matrice) {
        free(rooms);
        return 84;
    }

    // Affichage de la matrice pour debug
    print_matrice(matrice);

    // Création de la file pour BFS
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue) {
        free_matrice(matrice, rooms->nb_rooms);
        free(rooms);
        return 84;
    }

    init_queue(queue, rooms->nb_rooms);
    def_queue(rooms, queue);  // Remplissage de la queue

    // Exécution de BFS
    node_t *start_node = malloc(sizeof(node_t));  // Départ (index 0)
    node_t *end_node = malloc(sizeof(node_t));    // Arrivée (index 3)

    start_node  = def_node("0", 1, 0);
    end_node    = def_node("3", 0, 1);
    int found = bfs(start_node, end_node, rooms, matrice);
    if (found)
        printf("Chemin trouvé !\n");
    else
        printf("Aucun chemin trouvé.\n");

    // Nettoyage mémoire
    free(queue->items);
    free(queue);
    free_matrice(matrice, rooms->nb_rooms);
    free(rooms->start);
    free(rooms->rooms);
    free(rooms->end);
    free(rooms);

    return 0;
}
