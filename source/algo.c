/*
** EPITECH PROJECT, 2024
** setting_up_tek_1_re
** File description:
** algo
*/

#include "../include/my.h"

int check_char(char **array, stock_value_t *map)
{
    if (array[map->y + map->n] == NULL ||
        array[map->y][map->x + map->n] == '\0') {
        map->check = false;
        return 1;
    }
    for (map->i = 0; map->i <= map->n; map->i++)
        if (array[map->y + map->i][map->x + map->n] == 'o') {
            map->check = false;
            return 1;
        }
    for (map->i = 0; map->i <= map->n - 1; map->i++)
        if (array[map->y + map->n][map->x + map->i] == 'o') {
            map->check = false;
            return 1;
        }
    map->check = true;
    return 0;
}

static int counter(char **array, stock_value_t *map)
{
    map->check = true;
    for (map->n = 0; map->check != false; map->n++) {
        check_char(array, map);
    }
    if (map->value < map->n - 1) {
        map->value = map->n - 1;
        map->coord_y = map->y;
        map->coord_x = map->x;
        map->check = true;
    }
    return 0;
}

int algo(char **array, stock_value_t *map)
{
    if (array[0][0] == '-')
        return 84;
    map->i = 0;
    map->n = 0;
    map->count = 0;
    map->value = 0;
    for (map->y = 0; array[map->y] != NULL; map->y++) {
        for (map->x = 0; array[map->y][map->x] != '\0'; map->x++) {
            counter(array, map);
        }
    }
    return 0;
}
