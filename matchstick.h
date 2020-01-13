/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_
#ifndef  READ_SIZE
#define  READ_SIZE 256
#endif

//getnextline
char *get_next_line(int fd);
char *my_strcat(char **dest, char const *src);
void shift_buffer(char *buffer, int buffer_size);
int replace(char *str, char a, char b);
int my_strlen(char const *str);
char *get_next_line(int fd);

//display
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
void display_triangle(int n);
void player_instruction(int input_line, int input_matches);

int my_getnbr(char const *str);
int my_isnb(char c);

void next_instruction(char *matches, char *line);

#endif /* !MATCHSTICK_H_ */