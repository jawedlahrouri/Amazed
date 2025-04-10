/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** my_memset.c
*/

#include <string.h>

void *my_memset(void *s, int c, size_t n)
{
    int i = 0;
    unsigned char *ptr = s;

    while (n) {
        ptr[i] = (unsigned char)c;
        n--;
    }
    return s;
}
