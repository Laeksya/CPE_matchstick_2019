/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my
*/
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_base_unsigned(unsigned  long long int nb, char const *base);
int my_putnbr_unsigned(unsigned int nb);
int my_strlen(char const *str);
void flags(char const *str, va_list ap, int c);
int my_printf(const char *format, ...);
void print_xb(va_list ap);
void print_c(va_list ap);
void print(va_list ap);
void print_o(va_list ap);
void print_s(va_list ap);
void print_d(va_list ap);
void print_i(va_list ap);
void print_u(va_list ap);
void print_x(va_list ap);
void print_b(va_list ap);