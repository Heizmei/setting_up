/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** transform a string into a array
*/

#include "my.h"

static int my_len(char const *str)
{
    int len = 0;

    if (str == NULL)
        return 84;
    for (; str[len] != '\0'; len++);
    return len;
}

char **my_str_to_word_array(char const *str)
{
    int len = my_len(str);
    int nb = 0;
    int i = 0;
    int tmp = 0;
    char **array = malloc(sizeof(char *) * len + 1);

    if (str == NULL || array == NULL)
        return NULL;
    for (; str[tmp] != '\0'; i++) {
        array[i] = malloc(sizeof(char) * len + 1);
        for (nb = 0; str[tmp] != '\n' && str[tmp] != '\0'; nb++) {
            array[i][nb] = str[tmp];
            tmp++;
        }
        array[i][nb] = '\0';
        tmp++;
    }
    array[i] = NULL;
    return array;
}
