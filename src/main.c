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

int main(int argc, char **argv)
{
    if (argc <= 1) {
        return 84;
    }
    way_t link1 = {1, 0};
    way_t link2 = {3, 2};
    way_t link3 = {0, 4};
    way_t link4 = {1, 3};
    way_t *tab[] = {&link1, &link2, &link3, &link4, NULL};
    matrice_t *matrice = def_matrice(tab, 5);
    if (!matrice) {
        return 84;
    }
    print_matrice(matrice, 4);
    for (int i = 0; i < 5; i++)
        free(matrice->matrice_link[i]);
    free(matrice->matrice_link);
    free(matrice);
    return 0;
}
