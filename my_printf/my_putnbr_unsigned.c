/*
** EPITECH PROJECT, 2019
** my_putnbr_unsigned
** File description:
** my_putnbr_unsigned
*/

void my_putchar(char c);

int my_putnbr_unsigned(unsigned int nb)
{
    if (nb >= 10) {
        my_putnbr_unsigned(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return (0);
}