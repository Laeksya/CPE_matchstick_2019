/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** counts_and_return_the_number_of_characters
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}