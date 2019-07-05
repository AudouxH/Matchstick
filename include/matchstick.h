/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** matchstick.h
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int playing_game(char **game_board, char **av);
int display_map_in_game(char **game_board, char **av, int nb_stick_total);
int recovery_argv_line(char **av);
int recovery_argv_match(char **av);
void display_message_player(int nb_line, int nb_match);
char **change_board(char **game_board, int nb_line, int nb_match, char **av);
void display_message_ia(int line);
char **change_board_ia(char **game_board, char **av);
int playing_game(char **game_board, char **av);
int count_total_stick(char **game_board, char **av);
char **generate_map(char **av);
char **padding_map(char **game_board, char **av);
char *first_line(int nb_cols);
char *corps_line(int nb_stick, int nb_space, int nb_cols);
int error_gestion(int ac, char **av);
void display_game_board(char **game_board, char **av);
char **print_game_board(char **av);
void my_putchar(char c);
void my_putstr(char const *str);
int my_getnbr(char const *str);
int find_digit(int x);
void disp_val(int v);
int my_put_nbr(int nb);