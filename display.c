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
    if (nb == -2147483648)
        my_putstr("-2147483648");
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
    return (0);
}

/* void ia_instruction(void)
{
    my_putstr("AI's turn...");
    my_putstr("AI removed ");
     my_putstr(matches);
    my_putstr(" match(es) from line ");
     my_putstr(line);
    my_putchar('\n');
} */
void after_wrong_matches(int input_matches, char *matches, int nb_matches)
{   if (nb_matches > input_matches) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(input_matches);
        my_putstr(" matches per turn\n");
        my_putstr("Matches: ");
        matches = get_next_line(0);
    }
    if (nb_matches < 0) {
        my_putstr("Error: you have to remove at least one match");
        my_put_nbr(input_matches);
        my_putstr(" matches per turn\n");
        my_putstr("Matches: ");
        matches = get_next_line(0);
    }
}

void next_instruction(char *matches, char *line)
{
    my_putstr("Player removed ");
    my_putstr(matches);
    my_putstr(" match(es) from line ");
    my_putstr(line);
    my_putchar('\n');
}