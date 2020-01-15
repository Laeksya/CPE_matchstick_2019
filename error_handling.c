/*
** EPITECH PROJECT, 2020
** Merror_handling.c
** File description:
** error_handling
*/

#include "matchstick.h"
#include <stdlib.h>

void not_enough_matches(map_t *map, int input_matches, char *matches,
int input_line)
{
    for (int i = 0; i < my_strlen(matches); i++) {
        if (my_isnb(matches[i]) == 0) {
            my_putstr("Error: invalid input (positive number expected)\n");
            player_instruction(input_line, input_matches, map);
        }
    }
    /* if (input_matches > map->nb_matches[input_line]) {
        my_putstr("Error: not enough matches on this line\n");
        player_instruction(input_line, input_matches, map);
    } */
}

void error(map_t *map, int input_matches, int nb_matches, int input_line)
{
    if (nb_matches > input_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(input_matches);
        my_putstr(" matches per turn\n");
        player_instruction(input_line, input_matches, map);
    }
    if (nb_matches < 0) {
        my_putstr("Error: you have to remove at least one match\n");
        player_instruction(input_line, input_matches, map);
    }
}

int rand_line(int nb)
{
    int line = random()%(nb-1) + 1;

    return (line);
}