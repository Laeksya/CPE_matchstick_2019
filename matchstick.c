/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick
*/

#include "matchstick.h"

void player_instruction(int input_line, int input_matches)
{
    my_putstr("Your turn:\nLine: ");
    char *line = get_next_line(0);
    int nb_lines = my_getnbr(line);
    if (nb_lines > input_line || nb_lines < 0) {
        my_putstr("Error: this line is out of range");
        player_instruction(input_line, input_matches);
    }
    my_putstr("Matches: ");
    char *matches = get_next_line(0);
    int nb_matches = my_getnbr(matches);
    if (nb_matches > input_matches || nb_lines < 0) {
       my_putstr("Error: you cannot remove more than ");
       my_put_nbr(input_matches);
       my_putstr(" matches per turn\n");
       my_putstr("Matches: ");
       matches = get_next_line(0);
    }
    next_instruction(matches, line);
}

void display_triangle(int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 1 + (2 * n); i++)
        my_putchar('*');
    my_putchar('\n');
    for (i = 1; i <= n; i++) {
        my_putchar('*');
        for (j = 0; j < n - i; j++)
            my_putchar(' ');
        for ( j = 0; j < (2 * i - 1); j++)
            my_putchar('|');
         for (j = 0; j < n - i; j++)
            my_putchar(' ');
        my_putchar('*');
        my_putchar('\n');
    }
    for (i = 0; i < 1 + (2 * n); i++)
         my_putchar('*');
    my_putchar('\n');
}