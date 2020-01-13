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

void instruction(void)
{
    my_putstr("Your turn:\nLine: ");
    char *line = get_next_line(0);
    my_putstr("Matches: ");
    char *matches = get_next_line(0);
    my_putstr("Player removed ");
    my_putstr(matches);
    my_putstr(" match(es) from line ");
    my_putstr(line);
    my_putchar('\n');
}

void display_triangle(int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 1 + (2 * n); i++)
        my_putchar('*');
    my_putchar('\n');
    for (i = 1; i <= n; i++) {
        my_putchar('*');
        for (j = 0; j < n - i; j++)
            my_putchar(' ');
        for ( j = 0; j < (2 * i - 1); j++)
            my_putchar('|');
         for (j = 0; j < n - i; j++)
            my_putchar(' ');
        my_putchar('*');
        my_putchar('\n');
    }
    for (i = 0; i < 1 + (2 * n); i++)
         my_putchar('*');
    my_putchar('\n');
    instruction();
}