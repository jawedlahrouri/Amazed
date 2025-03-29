/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h BOOTCAMP
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdint.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>

/*Struct*/
typedef struct link {
    int data;
    struct link *next;
} link_t;

typedef struct way {
    int first_room;
    int second_room;
} way_t;

typedef struct matrice {
    int **matrice_link;
    way_t **tab_link;
    int nb_room;
} matrice_t;

typedef struct room {
    int *start;
    int *rooms;
    int *end;
} room_t;

/*Function*/

// matrice handling
void print_matrice(matrice_t *matrice, int nb_room);
matrice_t *def_matrice(way_t **tab, int nb_room);

int main(int argc, char **argv);
#endif /* !MY_H_ */
