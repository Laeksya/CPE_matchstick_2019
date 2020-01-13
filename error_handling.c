/*
** EPITECH PROJECT, 2020
** Merror_handling.c
** File description:
** error_handling
*/

#include "matchstick.h"

void after_wrong_matches(int input_matches, char *matches, int nb_matches)
{
    if (nb_matches > input_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(input_matches);
        my_putstr(" matches per turn\n");
        my_putstr("Matches: ");
        matches = get_next_line(0);
    }
    if (nb_matches < 0) {
        my_putstr("Error: you have to remove at least one match\n");
        my_putstr("Matches: ");
        matches = get_next_line(0);
    }
}

void not_enough_matches(map_t *map, int input_matches, char *matches,
int input_line)
{
    for (int i = 0; i < my_strlen(matches); i++) {
        if (my_isnb(matches[i]) == 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        my_putstr("Matches: ");
        matches = get_next_line(0);
        }
    }
    if (map->nb_matches[input_line] < 2 * input_line - 1) {
        my_putstr("Error: not enough matches on this line\n");
        my_putstr("Matches: ");
        matches = get_next_line(0);
    }



}
/*
{
    my_putstr("AI's turn...");
    my_putstr("AI removed ");
    my_putstr(matches);
    my_putstr(" match(es) from line ");
    my_putstr(line);
    my_putchar('\n');
} */