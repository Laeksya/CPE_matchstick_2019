/*
** EPITECH PROJECT, 2019
** my_putnbr_base.c
** File description:
** putnbr_base
*/

#include"my.h"

int my_putnbr_base(int nb, char const *base)
{
    int base_len = my_strlen(base);

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= base_len) {
        my_putnbr_base(nb / base_len, base);
    }
    my_putchar(base[nb % base_len]);
    return (0);
}