/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** lib.c
*/

#include "../include/matchstick.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            while (str[i] >= '0' && str[i] <= '9') {
                nb = (nb * 10) + str[i] - '0';
                i++;
            }
            if (str[0] == 45)
                return (nb * -1);
            return (nb);
        }
    }
}