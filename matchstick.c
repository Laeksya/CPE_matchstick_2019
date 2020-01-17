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
    wrong_line(input_line, input_matches, nb_lines, map);
    my_putstr("Matches: ");
    char *matches = malloc(sizeof(char) * 1);
    getline(&matches, &size, stdin);
    int nb_matches = my_getnbr(matches);
    /* invalid_input(map, input_matches, matches, input_line); */
    error(map, input_matches, nb_matches, input_line);
    if (not_enough_matches(nb_matches, nb_lines, map) == 1)
        player_instruction(input_line, input_matches, map);
    next_instruction(matches, line);
    map->nb_matches[nb_lines - 1] -= nb_matches;
    display_map(map);
    ia(map, nb_lines, nb_matches);

}

int ia(map_t *map, int nb_lines, int nb_matches)
{
    int matches = 1;
    int line = 0;

    line = rand_line(map->nb_line);
    if (map->nb_matches == 0)
        line = rand_line(map->nb_line);
    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    map->nb_matches[nb_lines - 1] -= nb_matches;
    display_map(map);
    return (0);
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!('0' <= str[i] && str[i] >= '9'))
        return (0);
    i++;
    }
    return (1);
}