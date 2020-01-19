/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** function_for_printf2
*/

#include "my.h"

void print_X(va_list ap)
{
    my_putnbr_base_unsigned(va_arg(ap, unsigned int), "0123456789ABCDEF");
}

void print_c(va_list ap)
{
    my_putchar((char)va_arg(ap, int));
}

void print(va_list ap)
{
    my_putchar('%');
}

void print_o(va_list ap)
{
    my_putnbr_base_unsigned(va_arg(ap, int), "01234567");
}

void print_b(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}