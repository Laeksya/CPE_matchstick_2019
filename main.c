/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** the_main_function
*/

#include <stdlib.h>
#include <unistd.h>
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

int main(int ac, char **av)
{
    int nb_line = my_getnbr(av[1]);
    int nb_matches = my_getnbr(av[2]);

    for (int i = 0; av[1][i] != '\0' && av[2][i] != '\0'; i++)
        if (ac != 3 || my_isnb(av[1][i]) == 0 || my_isnb(av[2][i]) == 0)
            return (84);
    display_triangle(nb_line);
    player_instruction(nb_line, nb_matches);
    return (0);
}