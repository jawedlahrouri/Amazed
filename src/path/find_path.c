/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** find_path.c
*/

#include "my.h"
#include "lib.h"

/*
faire une fonction qui parcour tout les chemins et qui vas comparer avec un compteur pour avoir le plus petit cette fonction 
devras return une struct avec le la list de char * correspondant au chemin le plus court et le compteur de tick
une fois fais faire une struct robot avec le chemin qu'il faut emprinter, le tick, en combien de position il part
*/

int *find_path(matrice_t *matrice)
{
    int count = 0;

    for (int i = 0; matrice->matrice_link[i] < matrice->nb_room; i++) {
        for (int j = 0; matrice->matrice_link[i][j] < matrice->nb_room; j++) {
            
        }
    }
}