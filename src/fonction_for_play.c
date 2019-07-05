/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** fonction_for_play.c
*/

#include "../include/matchstick.h"

int count_total_stick(char **game_board, char **av)
{
    int nb_map = my_getnbr(av[1]);
    int nb_cols = ((nb_map * 2) + 2);
    int nb_rows = (nb_map + 2);
    int nb_compt_stick = 0;

    for (int i = 0; i < nb_rows; i++)
        for (int y = 0; y < nb_cols; y++)
            if (game_board[i][y] == '|')
                nb_compt_stick++;
    return (nb_compt_stick);
}