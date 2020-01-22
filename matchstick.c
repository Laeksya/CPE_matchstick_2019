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
    display_map(map);
    player_islosing(map);
    return (0);
}

int player_instruction(int input_line, int input_matches, map_t *map)
{
    my_printf("Line: ");
    __ssize_t return_getline = 0;
    char *line = NULL;
    size_t size = 1;
    return_getline = getline(&line, &size, stdin);
    if (return_getline <= 0)
        return (33);
    int nb_lines = my_getnbr(line);
    wrong_line(input_line, input_matches, nb_lines, map);
    invalid_input_line(map, input_matches, line, input_line);
    char *matches = NULL;
    my_printf("Matches: ");
    return_getline = getline(&matches, &size, stdin);
    if (return_getline <= 0)
        return (33);
    int nb_matches = my_getnbr(matches);
    invalid_input(map, input_matches, matches, input_line);
    error(map, input_matches, nb_matches, input_line);
    if (not_enough_matches(nb_matches, nb_lines, map) == 1)
        player_instruction(input_line, input_matches, map);
    else
        display_next_instructions(nb_lines, nb_matches, map);
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