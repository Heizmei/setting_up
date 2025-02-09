/*
** EPITECH PROJECT, 2024
** setting_up_tek1_re
** File description:
** bs_setting_up.c
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

size_t size_stock(char const *argv[])
{
    struct stat file;

    if (stat(argv[1], &file) == -1)
        return 0;
    return file.st_size;
}

int print_func(char **array, stock_value_t *map)
{
    if (map == NULL || !array || !array[0])
        return 84;
    for (int i = 0; i < map->value; i++) {
        for (int x = 0; x < map->value; x++) {
            array[map->coord_y + i][map->coord_x + x] = 'x';
        }
    }
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        write(1, "\n", 1);
    }
    return 0;
}

int check_map_char(char **array, int i)
{
    if (!array || !array[0])
        return 84;
    for (int nb = 0; array[i][nb]; nb++) {
        if (array[i][nb] == '.')
            return 1;
    }
    return 0;
}

int check_map(char **array)
{
    if (!array || !array[0])
        return 84;
    for (int i = 0; array[i]; i++) {
        if (check_map_char(array, i) == 1)
            return 0;
    }
    return 84;
}

int setting_up(char const *argv[])
{
    size_t size = size_stock(argv);
    struct stock_value_s *map = malloc(sizeof(stock_value_t));
    char *new_str = malloc(sizeof(char) * size + 1);
    char **array;
    int fd = open(argv[1], O_RDONLY);

    read(fd, new_str, size);
    if (fd == -1 || !map || !new_str)
        return 84;
    array = my_str_to_word_array(new_str);
    if (!array || !array[0] || algo(array, map) == 84 ||
        check_map(array) == 84)
        return 84;
    print_func(array, map);
    free(new_str);
    free(map);
    return 0;
}
