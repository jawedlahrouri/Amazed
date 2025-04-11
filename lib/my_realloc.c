/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-amazed-jawed.lahrouri
** File description:
** my_realloc.c
*/

#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t new_size)
{
    size_t min_size = new_size;
    char *src = (char *)ptr;
    void *new_ptr = malloc(new_size);
    char *dest = (char *)new_ptr;

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
        return malloc(new_size);
    if (!new_ptr)
        return NULL;
    for (size_t i = 0; i < min_size; i++) {
        dest[i] = src[i];
    }
    free(ptr);
    return new_ptr;
}
