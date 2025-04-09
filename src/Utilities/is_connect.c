/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** is_connect.c
*/

#include "lib.h"
#include "my.h"

int is_connect(node_t *node1, node_t *node2, matrice_t *matrice)
{
    // printf(" looooooool %i\n", matrice->matrice_link[0][1]);
    printf("node idx : %i\nnew_node idx : %i\nis_connect : %i\n", node1->idx, node2->idx, matrice->matrice_link[node1->idx][node2->idx]);
    if (matrice->matrice_link[node1->idx][node2->idx] == 1)
        return 0;
    else
        return 1;
}