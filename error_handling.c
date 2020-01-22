/*
** EPITECH PROJECT, 2020
** Merror_handling.c
** File description:
** error_handling
*/

#include "matchstick.h"
#include <stdlib.h>

int invalid_input(map_t *map, int input_matches, char *matches,
int input_line)
{
    for (int i = 0; matches[i] != '\n'; i++)
        if (!(matches[i] >= '0' &&  matches[i] <= '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    return (0);
}

int invalid_input_line(map_t *map, int input_matches, char *line,
int input_line)
{
    for (int i = 0; line[i] != '\n'; i++)
        if (!(line[i] >= '0' &&  line[i] <= '9')) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (1);
        }
    return (0);
}

int error(map_t *map, int input_matches, int nb_matches, int input_line)
{
    if (nb_matches > input_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(input_matches);
        my_putstr(" matches per turn\n");
        return (1);
    }
    if (nb_matches <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    return (0);
}

int not_enough_matches(int nb_matches, int nb_lines, map_t *map)
{
    if (nb_matches > map->nb_matches[nb_lines - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    return (0);
}

int wrong_line(int input_line, int input_matches, int nb_lines, map_t *map)
{
    if (nb_lines > input_line) {
        my_putstr("Error: this line is out of range\n");
        player_instruction(input_line, input_matches, map);
        return (1);
    }
    if (nb_lines <= 0) {
        my_putstr("Error: this line is out of range\n");
        player_instruction(input_line, input_matches, map);
    return (1);
    }
    return (0);
}