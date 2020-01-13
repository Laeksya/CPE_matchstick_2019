/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** displays_characters_one_by_one
*/

#include <unistd.h>
#include "matchstick.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return (0);
}

void ia_instruction(void)
{
    my_putstr("AI's turn...");
    my_putstr("AI removed ");
    /* my_putstr(matches); */
    my_putstr(" match(es) from line ");
    /* my_putstr(line); */
    my_putchar('\n');
}

void next_instruction(char *matches, char *line)
{
    my_putstr("Player removed ");
    my_putstr(matches);
    my_putstr(" match(es) from line ");
    my_putstr(line);
    my_putchar('\n');
}