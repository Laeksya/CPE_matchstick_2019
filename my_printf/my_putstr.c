/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** displays_characters_one_by_one
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}