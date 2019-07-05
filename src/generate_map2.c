/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** generate_map2.c
*/

#include "../include/matchstick.h"

char **generate_map(char **av)
{
    int nb_map = my_getnbr(av[1]);
    int nb_rows = (nb_map * 2);
    int nb_cols = ((nb_map * 2) + 2);
    char **game_board = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++)
        game_board[i] = malloc(nb_cols);
    return (game_board);
}

char **padding_map(char **game_board, char **av)
{
    int nb_map = my_getnbr(av[1]);
    int nb_cols = ((nb_map * 2) + 2);
    int nb_rows = (nb_map + 2);
    int nb_space = (nb_map - 1);
    int nb_stick = 1;

    game_board[0] = first_line(nb_cols);
    for (int y = 1; y < (nb_map + 1); y++) {
        game_board[y] = corps_line(nb_stick, nb_space, nb_cols);
        nb_space--;
        nb_stick = nb_stick + 2;
    }
    game_board[nb_rows - 1] = first_line(nb_cols);
    return (game_board);
}

char *first_line(int nb_cols)
{
    char *first_line = malloc(nb_cols);

    for (int i = 0; i < nb_cols - 1; i++)
        first_line[i] = '*';
    first_line[nb_cols - 1] = '\n';
    return (first_line);
}

char *corps_line(int nb_stick, int nb_space, int nb_cols)
{
    char *corps_line = malloc(nb_cols);
    int pos = 0;

    corps_line[pos] = '*';
    pos++;
    for (int i = 0; i < nb_space; i++) {
        corps_line[pos] = ' ';
        pos++;
    }
    for (int i = 0; i < nb_stick; i++) {
        corps_line[pos] = '|';
        pos++;
    }
    for (int i = 0; i < nb_space; i++) {
        corps_line[pos] = ' ';
        pos++;
    }
    corps_line[pos] = '*';
    pos++;
    corps_line[pos] = '\n';
    return (corps_line);
}