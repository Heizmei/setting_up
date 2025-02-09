/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** make the fusion of two string
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int my_strlen(char const *str)
{
    int nb = 0;

    if (str == NULL)
        return 84;
    for (nb = 0; str[nb] != '\0'; nb++);
    return nb;
}

char *my_strcat(char *dest, char *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    int i = 0;

    if (!dest && !src)
        return NULL;
    if (dest == NULL) {
        return src;
    }
    if (src == NULL) {
        return dest;
    }
    for (; i != len_dest + len_src; i++) {
        dest[i + len_dest] = src[i];
    }
    dest[i + 1] = '\0';
    return dest;
}
