/*
** EPITECH PROJECT, 2020
** matchstick.c
** File description:
** matchstick
*/

#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_printf/my.h"

int display_next_instructions(int nb_lines, int nb_matches, map_t *map)
{
    next_instruction(nb_matches, nb_lines);
    map->nb_matches[nb_lines - 1] -= nb_matches;
    player_islosing(map);
    return (0);
}

int player_instruction(int input_line, int input_matches, map_t *map)
{
    char *line = NULL;
    size_t size = 1;
    int nb_lines = 0;
    int err = 0;
    int nb_matches = 0;
    char *matches = NULL;

    do {
        err = 0;
        my_printf("Line: ");
        if (getline(&line, &size, stdin) <= 0)
            return (33);
        nb_lines = my_getnbr(line);
        if (invalid_input_line(map, input_matches, line) == 1 ||
        wrong_line(input_line, nb_lines) == 1) {
            err = 1;
            continue;
        }
        my_printf("Matches: ");
        if (getline(&matches, &size, stdin) <= 0)
            return (33);
        nb_matches = my_getnbr(matches);
        if (not_enough_matches(nb_matches, nb_lines, map) == 1 ||
        error(input_matches, nb_matches) == 1 || invalid_input(map,
        input_matches, matches, input_line) == 1)
            err = 1;
    } while (err);
    display_next_instructions(nb_lines, nb_matches, map);
    return (0);
}

int ia(map_t *map)
{
    int nb_matches = 1;
    int nb_line = 0;

    nb_line = rand_line(map->nb_line);
    while (nb_matches > map->nb_matches[nb_line - 1])
        nb_line = rand_line(map->nb_line + 1);
    my_printf("%s%i", "AI's turn...\nAI removed ", nb_matches);
    my_printf(" match(es) from line %i\n", nb_line);
    map->nb_matches[nb_line - 1] -= nb_matches;
    if (check_victory(map) == 1) {
        map->victory = 1;
        display_mapv(map);
    }
    return (0);
}

int check_victory(map_t *map)
{
    for (int i = 0; i <= map->nb_line; i++)
        if (map->nb_matches[i] != 0)
            return (0);
    return (1);
}

int victory_message(map_t *map)
{
    if (map->victory == 2) {
        my_printf("You lost, too bad...\n");
        return (2);
    }
    if (map->victory == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (0);
}