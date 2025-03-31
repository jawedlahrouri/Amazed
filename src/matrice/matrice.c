/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** define_matrice.c
*/

#include "my.h"
#include "lib.h"

void print_matrice(matrice_t *matrice)
{
    if (!matrice || !matrice->matrice_link)
        return;
    my_printf("Matrice d'adjacence :\n");
    for (int i = 0; i < matrice->nb_room; i++) {
        for (int j = 0; j < matrice->nb_room; j++) {
            printf("%d ", matrice->matrice_link[i][j]);
        }
        printf("\n");
    }
}

void get_link(matrice_t *matrice, int i, int y)
{
    way_t *link = NULL;

    if (!matrice || !matrice->tab_link)
        return;
    for (int j = 0; matrice->tab_link[j] != NULL; j++) {
        link = matrice->tab_link[j];
        if ((link->first_room == i && link->second_room == y) ||
            (link->first_room == y && link->second_room == i)) {
            matrice->matrice_link[i][y] = 1;
            matrice->matrice_link[y][i] = 1;
            return;
        }
    }
}

int fill_matrice(matrice_t *matrice)
{
    int first = 0;
    int second = 0;
    way_t *link = NULL;

    if (!matrice || !matrice->matrice_link)
        return 84;
    for (int i = 0; i < matrice->nb_room; i++) {
        for (int y = 0; y < matrice->nb_room; y++)
            matrice->matrice_link[i][y] = 0;
    }
    for (int j = 0; matrice->tab_link[j] != NULL; j++) {
        link = matrice->tab_link[j];
        first = link->first_room;
        second = link->second_room;
        if (first < matrice->nb_room && second < matrice->nb_room) {
            matrice->matrice_link[first][second] = 1;
            matrice->matrice_link[second][first] = 1;
        }
    }
    return 0;
}

void free_matrice(matrice_t *matrice, int nb_room)
{
    if (!matrice)
        return;
    for (int i = 0; i < nb_room; i++) {
        free(matrice->matrice_link[i]);
    }
    free(matrice->matrice_link);
    free(matrice);
}
