/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** define_matrice.c
*/

#include "my.h"
#include "lib.h"

void print_matrice(matrice_t *matrice, int nb_room)
{
    if (!matrice || !matrice->matrice_link)
        return;
    printf("Matrice d'adjacence :\n");
    for (int i = 0; i <= nb_room; i++) {
        for (int j = 0; j <= nb_room; j++) {
            printf("%d ", matrice->matrice_link[i][j]);
        }
        printf("\n");
    }
}

void get_link(matrice_t *matrice, int i, int y)
{
    if (!matrice || !matrice->tab_link)
        return;

    for (int j = 0; matrice->tab_link[j] != NULL; j++) {
        way_t *link = matrice->tab_link[j];

        if ((link->first_room == i && link->second_room == y) ||
            (link->first_room == y && link->second_room == i)) {
            matrice->matrice_link[i][y] = 1;
            matrice->matrice_link[y][i] = 1;
        }
    }
}

void fill_matrice(matrice_t *matrice, int nb_room)
{
    if (!matrice || !matrice->matrice_link)
        return;

    for (int i = 0; i < nb_room; i++) {
        for (int y = 0; y < nb_room; y++) {
            matrice->matrice_link[i][y] = 0;
            get_link(matrice, i, y);
        }
    }
}

matrice_t *def_matrice(way_t **tab, int nb_room)
{
    matrice_t *matrice = malloc(sizeof(matrice_t));

    if (!matrice)
        return NULL;
    matrice->tab_link = tab;
    matrice->matrice_link = malloc(sizeof(int *) * nb_room);
    if (!matrice->matrice_link) {
        free(matrice);
        return NULL;
    }
    for (int i = 0; i < nb_room; i++) {
        matrice->matrice_link[i] = malloc(sizeof(int) * nb_room);
        if (!matrice->matrice_link[i]) {
            for (int j = 0; j < i; j++)
                free(matrice->matrice_link[j]);
            free(matrice->matrice_link);
            free(matrice);
            return NULL;
        }
        for (int j = 0; j < nb_room; j++) {
            matrice->matrice_link[i][j] = 0;
        }
    }
    fill_matrice(matrice, nb_room);
    return matrice;
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

/*
faire une fonction qui parcour tout les chemins et qui vas comparer avec un compteur pour avoir le plus petit cette fonction 
devras return une struct avec le la list de char * correspondant au chemin le plus court et le compteur de tick
une fois fais faire une struct robot avec le chemin qu'il faut emprinter, le tick, en combien de position il part
*/