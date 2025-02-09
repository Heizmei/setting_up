/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** print a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    if (!str)
        return 84;
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
    return 0;
}
