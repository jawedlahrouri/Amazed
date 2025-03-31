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

/*
Faire des utilities style is_connect, is_end
Faire des queues avec une struct
*/

// void is_unit_end(int unit, room_t *rooms, int id_rooms, int coord)
// {
//     if (id_rooms == coord && id_rooms != rooms->end)
//         return 84;
//     if (coord == rooms->end)
//         return 84;
// }

// void find_good_ways(matrice_t *matrice, room_t *rooms, int id_rooms)
// {
//     valid_path_t *head = NULL;
//     int unit = matrice->matrice_link[id_rooms][0];
//     for (int i = 0; unit != NULL; i++) {
//         if (matrice->matrice_link[id_rooms][i] == 1) {
//             unit = matrice->matrice_link[i][0];
//         }
//         else {
//             is_unit_end(unit, head, id_rooms, i);
//         }
//         unit = matrice->matrice_link[id_rooms][i];
//     }
// }

// int *find_path(matrice_t *matrice, room_t *rooms)
// {
//     int len_start = 0; // avoir le nb de room entré

//     if (!rooms)
//         return 84;
//     for (int i = 0; i < len_start; i++) {
//         find_good_ways(matrice, rooms, rooms->start[i]);
//     }
// }