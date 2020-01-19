/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** function_for_printf
*/

#include "my.h"

void print_s(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void print_d(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void print_i(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void print_u(va_list ap)
{
    my_putnbr_unsigned(va_arg(ap, unsigned int));
}

void print_x(va_list ap)
{
    my_putnbr_base_unsigned(va_arg(ap, int), "01234567989abcdef");
}