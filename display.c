/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** displays_characters_one_by_one
*/

#include <unistd.h>
#include "matchstick.h"
#include "my_printf/my.h"

void next_instruction(char *matches, char *line)
{
    my_printf("Player removed %s%s%s", matches, "match(es) from line ", line);
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

void gameloop(int nb_line, int nb_matches, map_t *map)
{
    for (;;) {
        display_map(map);
        my_putstr("Your turn:\n");
        if (player_instruction(nb_line, nb_matches, map) == 33 || \
        map->victory != 0)
            break;
    }
}

void player_islosing(map_t *map)
{
    if (check_victory(map) == 1)
        map->victory = 2;
    else
        ia(map);
}