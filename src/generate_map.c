/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** print_game_board.c
*/

#include "../include/matchstick.h"

int error_gestion(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 98)
        return (84);
    if (my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 98)
        return (84);
}

void display_game_board(char **game_board, char **av)
{
    int nb_map = my_getnbr(av[1]);
    int nb_rows = (nb_map + 2);
    for (int i = 0; i < nb_rows; i++)
        my_putstr(game_board[i]);
}

char **print_game_board(char **av)
{
    char **game_board = generate_map(av);

    game_board = padding_map(game_board, av);
    return (game_board);
}