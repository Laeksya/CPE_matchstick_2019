/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** the_main_function
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "matchstick.h"

int my_isnb(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++)	{
    	if (str[i] == '-')
            sign *= -1;
    }
    for (; str[i] == ' '; ++i);
    for (; str[i] != '\0' && my_isnb(str[i]); i++) {
    	res = res * 10 + str[i] - '0';
    }
    return (sign * res);
}

int error_arg(int ac, char **av)
{
    srand(time(NULL));
    if (ac != 3)
        return (84);
    for (int i = 0; av[1][i] != '\0' && av[2][i] != '\0'; i++)
        if (my_isnb(av[1][i]) == 0 || my_isnb(av[2][i]) == 0)
            return (84);
    return (0);

}

int main(int ac, char **av)
{
    int nb_line = 1;
    int nb_matches = 1;
    map_t map;

    if (error_arg(ac, av) == 84)
        return (84);
    nb_line = my_getnbr(av[1]);
    nb_matches = my_getnbr(av[2]);
    map.nb_line = nb_line;
    map.nb_matches = malloc(sizeof(int) * nb_line);
    for (int i = 0; i < nb_line; i++)
        map.nb_matches[i] = 2 * i + 1;
    for (;;) {
        display_map(&map);
        my_putstr("Your turn:\n");
        player_instruction(nb_line, nb_matches, &map);
        if (player_instruction(nb_line, nb_matches, &map) == 33)
            break;
    }
    return (0);
}