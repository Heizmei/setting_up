/*
** EPITECH PROJECT, 2024
** setting_up_tek1_re
** File description:
** main.c
*/

#include "../include/my.h"

int main(int argc, char const *argv[])
{
    if (argc < 2)
        return 84;
    if (argc > 3)
        return 84;
    if (argc == 3)
        return generate_map(argv);
    if (argc == 2) {
        return setting_up(argv);
    }
}
