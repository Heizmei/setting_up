/*
** EPITECH PROJECT, 2023
** dhjn
** File description:
** sjxb
*/
#include "my.h"

int fonction(int a, int b, char const *c)
{
    if (c[a + 1] <= '0' || c[a + 1] >= '9')
        return b;
    return 84;
}

int my_getnbr(char const *str)
{
    int nbr = 0;

    if (str == NULL)
        return 84;
    for (int i = 0; str[i]; i += 1) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i]- '0';
            fonction(i, nbr, str);
        }
    }
    return (nbr);
}
