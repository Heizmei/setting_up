/*
** EPITECH PROJECT, 2024
** setting_up_tek_1_re
** File description:
** generate_map
*/

#include "my.h"

int my_getlen(char const *str)
{
    int nb = 0;

    if (!str)
        return 0;
    for (; str[nb] != '\0'; nb++);
    return nb;
}

int transform_gen_map(char *str, stock_value_t *map)
{
    char **array = my_str_to_word_array(str);

    if (str == NULL || !array || !array[0])
        return 84;
    algo(array, map);
    print_func(array, map);
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    return 0;
}

char *make_map(char *str, char *tmp, int size, stock_value_t *map)
{
    if (str == NULL || tmp == NULL || map == NULL) {
        return NULL;
    }
    for (int nb = 0; nb < size; nb++) {
        if (tmp[map->count] == '\0') {
            map->count = 0;
        }
        str[(nb + map->sto_i) + (size * map->sto_i)] = tmp[map->count];
        map->count++;
    }
    str[(size + map->sto_i) + (size * map->sto_i)] = '\n';
    return str;
}

int generate_map(char const *argv[])
{
    struct stock_value_s *map = malloc(sizeof(stock_value_t));
    int size = my_getnbr(argv[1]);
    char *str = malloc(sizeof(char) + (size * size));
    char *tmp = malloc(sizeof(char) * size);

    if (!str || !tmp || !map)
        return 84;
    for (int nb = 0; argv[2][nb] != '\0'; nb++) {
        tmp[nb] = argv[2][nb];
    }
    for (int i = 0; i != size; i++) {
        map->sto_i = i;
        str = make_map(str, tmp, size, map);
    }
    str[(size * size) + size] = '\0';
    transform_gen_map(str, map);
    free(map);
    return 0;
}
