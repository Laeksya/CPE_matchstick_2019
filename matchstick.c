/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick
*/

#include "matchstick.h"

void player_instruction(int input_line, int input_matches, map_t *map)
{
    my_putstr("Your turn:\nLine: ");
    char *line = get_next_line(0);
    int nb_lines = my_getnbr(line);
    if (nb_lines > input_line || nb_lines < 0) {
        my_putstr("Error: this line is out of range");
        player_instruction(input_line, input_matches, map);
    }
    my_putstr("Matches: ");
    char *matches = get_next_line(0);
    int nb_matches = my_getnbr(matches);
    after_wrong_matches(input_matches, matches, nb_matches);
    not_enough_matches(map, input_matches, matches, input_line);
    next_instruction(matches, line);
    map->nb_matches[nb_lines - 1] -= nb_matches;
}

void display_map(map_t *map)
{
    for (int i = 0; i < 1 + (2 * map->nb_line); i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i < map->nb_line; i++) {
        my_putchar('*');
        for (int j = 0; j < map->nb_line - i - 1; j++)
            my_putchar(' ');
        for (int j = 0; j < map->nb_matches[i]; j++)
            my_putchar('|');
        for (int j = 0; j < map->nb_line + i - map->nb_matches[i]; j++)
            my_putchar(' ');
        my_putstr("*\n");
    }
    for (int i = 0; i < 1 + (2 * map->nb_line); i++)
        my_putchar('*');
    my_putchar('\n');
}