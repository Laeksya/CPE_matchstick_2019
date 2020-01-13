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
    if (ac != 3)
        return(84);
    display_triangle(nb_line);
    return (0);
}