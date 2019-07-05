/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** change_map.c
*/

#include "../include/matchstick.h"

void display_message_player(int nb_line, int nb_match)
{
    my_putstr("Player removed ");
    my_put_nbr(nb_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(nb_line);
    my_putchar('\n');
}

char **change_board(char **game_board, int nb_line, int nb_match, char **av)
{
    int nb_map = my_getnbr(av[1]);
    int i = ((nb_map * 2) + 2);

    while (game_board[nb_line][i] != '|')
        i--;
    for (int y = 0; y < nb_match; y++) {
        game_board[nb_line][i] = ' ';
        i--;
    }
    display_message_player(nb_line, nb_match);
    display_game_board(game_board, av);
    return (game_board);
}

void display_message_ia(int line)
{
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(1);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

char **change_board_ia(char **game_board, char **av)
{
    int nb_map = my_getnbr(av[1]);
    int nb_cols = ((nb_map * 2) + 2);
    int nb_rows = (nb_map + 2);
    int line = 0;
    int cols = 0;

    for (int i = 0; i < nb_rows; i++)
        for (int y = 0; y < nb_cols; y++)
            if (game_board[i][y] == '|') {
                line = i;
                cols = y;
            }
    game_board[line][cols] = ' ';
    display_message_ia(line);
    display_game_board(game_board, av);
    return (game_board);
}
