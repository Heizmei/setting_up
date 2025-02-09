/*
** EPITECH PROJECT, 2024
** setting_up_tek1_re
** File description:
** my.h
*/

#ifndef LIST
    #define LIST
    #include "header.h"
    #include "struct.h"

int setting_up(char const *argv[]);
char **my_str_to_word_array(char const *str);
int algo(char **array, stock_value_t *map);
int my_putstr(char const *str);
int generate_map(char const *argv[]);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char *src);
int print_func(char **array, stock_value_t *map);
#endif
