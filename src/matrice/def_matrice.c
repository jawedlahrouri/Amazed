/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** def_matrice.c
*/

#include "my.h"
#include "lib.h"

int *allocate_matrice_row(int nb_room)
{
    int *row = malloc(sizeof(int) * nb_room);

    if (!row)
        return NULL;
    for (int i = 0; i < nb_room; i++)
        row[i] = 0;
    return row;
}

void free_matrice_rows(int **matrice_link, int nb_rows)
{
    if (!matrice_link)
        return;
    for (int i = 0; i < nb_rows; i++)
        free(matrice_link[i]);
    free(matrice_link);
}

int **allocate_matrice_rows(int nb_room)
{
    int **matrice_link = malloc(sizeof(int *) * nb_room);

    if (!matrice_link)
        return NULL;
    for (int i = 0; i < nb_room; i++) {
        matrice_link[i] = allocate_matrice_row(nb_room);
        if (!matrice_link[i]) {
            free_matrice_rows(matrice_link, i);
            return NULL;
        }
    }
    return matrice_link;
}

matrice_t *allocate_matrice(int nb_room)
{
    matrice_t *matrice = malloc(sizeof(matrice_t));

    if (!matrice)
        return NULL;
    matrice->nb_room = nb_room;
    matrice->matrice_link = allocate_matrice_rows(nb_room);
    if (!matrice->matrice_link) {
        free(matrice);
        return NULL;
    }
    return matrice;
}

matrice_t *def_matrice(way_t **tab, int nb_room)
{
    matrice_t *matrice = allocate_matrice(nb_room);

    if (!matrice)
        return NULL;
    matrice->tab_link = tab;
    if (fill_matrice(matrice) != 0) {
        free_matrice(matrice, nb_room);
        return NULL;
    }
    return matrice;
}
