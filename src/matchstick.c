/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** matchstick.c
*/

#include "../include/matchstick.h"

int main(int ac, char **av)
{
    if (error_gestion(ac, av) == 84)
        return (0);
    char **game_board = print_game_board(av);
    return (playing_game(game_board, av));
}

int playing_game(char **game_board, char **av)
{
    int nb_stick_total = count_total_stick(game_board, av);
    int nb_display = display_map_in_game(game_board, av, nb_stick_total);
    if (nb_display == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    if (nb_display == 2)
        my_putstr("You lost, too bad...\n");
    return (nb_display);
}

int display_map_in_game(char **game_board, char **av, int nb_stick_total)
{
    int av1 = my_getnbr(av[1]);
    int av2 = my_getnbr(av[2]);
    int line = 0;
    int match = 0;

    display_game_board(game_board, av);
    while (nb_stick_total > 0) {
        if ((line = recovery_argv_line(av)) == 84)
            return (0);
        if ((match = recovery_argv_match(av)) == 84)
            return (0);
        while (match < 1 || match > av2) {
            my_putstr("Error: you cannot remove more than ");
            my_put_nbr(av2);
            my_putstr(" matches per turn");
            if ((line = recovery_argv_line(av)) == 84)
                return (0);
            if ((match = recovery_argv_match(av)) == 84)
                return (0);
        }
        game_board = change_board(game_board, line, match, av);
        nb_stick_total = count_total_stick(game_board, av);
        if (nb_stick_total == 0)
            return (2);
        game_board = change_board_ia(game_board, av);
        nb_stick_total = count_total_stick(game_board, av);
        if (nb_stick_total == 0)
            return (1);
    }
}

int recovery_argv_line(char **av)
{
    char *str = NULL;
    size_t size;
    int nb_return = 0;
    int nb_map = my_getnbr(av[1]);

    my_putstr("\nYour turn:\nLine: ");
    if (getline(&str, &size, stdin) == -1)
        return (84);
    nb_return = my_getnbr(str);
    if (nb_return < 1 || nb_return > nb_map) {
        my_putstr("Error: this line is out of range");
        nb_return = recovery_argv_line(av);
    }
    else
        return (nb_return);
}

int recovery_argv_match(char **av)
{
    char *str = NULL;
    size_t size;
    int nb_return = 0;
    int nb_match = my_getnbr(av[2]);

    my_putstr("Matches: ");
    if (getline(&str, &size, stdin) == -1)
        return (84);
    nb_return = my_getnbr(str);
    return (nb_return);
}