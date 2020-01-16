/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick
*/

#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>

int player_instruction(int input_line, int input_matches, map_t *map)
{
    my_putstr("Your turn:\n");
    my_putstr("Line: ");
    __ssize_t return_getline = 0;
    char *line = malloc(sizeof(char) * 1);
    size_t size = 1;
    return_getline = getline(&line, &size, stdin);
    if (return_getline == EOF)
        return (33);
    int nb_lines = my_getnbr(line);
    if (nb_lines > input_line || nb_lines < 0) {
        my_putstr("Error: this line is out of range\n");
        player_instruction(input_line, input_matches, map);
    }
    my_putstr("Matches: ");
    char *matches = malloc(sizeof(char) * 1);
    getline(&matches, &size, stdin);
    int nb_matches = my_getnbr(matches);
    error(map, input_matches, nb_matches, input_line);
    if (not_enough_matches(nb_matches, nb_lines, map) == 1)
        player_instruction(input_line, input_matches, map);
    /* invalid_input(map, input_matches, matches, input_line); */
    next_instruction(matches, line);
    map->nb_matches[nb_lines - 1] -= nb_matches;
    display_map(map);
    ia(map);
}

void ia(map_t *map)
{
    int matches = 1;
    int line = 0;

    line = rand_line(map->nb_line);
    while (map->nb_matches == 0)
        line = rand_line(map->nb_line);
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}