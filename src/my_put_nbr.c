/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** my_put_nbr.c
*/

#include "../include/matchstick.h"

int find_digit(int x)
{
    int i = 0;
    while (x > 0) {
        x = x / 10;
        i++;
    }
    return (i);
}

void disp_val(int v)
{
    int x;
    if (v <= 9) {
        my_putchar(48 + v);
    } else {
        x = v / 10;
        x *= 10;
        my_putchar(48 + (v - x));
    }
}

int	my_put_nbr(int nb)
{
    int nbrcpy = nb;
    int compt = 0;

    if (nb < 0) {
        my_putchar('-');
        nbrcpy = nb * (-1);
    }

    if (nbrcpy > -1) {
        if (nbrcpy > 9) {
            compt = (nbrcpy % 10);
            nbrcpy = (nbrcpy - compt) / 10;
            my_put_nbr(nbrcpy);
            my_putchar(48 + compt);
        }
        else
            my_putchar(nbrcpy + '0');
    }
}