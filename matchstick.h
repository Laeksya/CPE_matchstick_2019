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

typedef struct
{
    int nb_line;
    int *nb_matches;
} map_t;

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
void display_map(map_t *map);
void player_instruction(int input_line, int input_matches, map_t *map);

int my_getnbr(char const *str);
int my_isnb(char c);

void next_instruction(char *matches, char *line);
void after_wrong_matches(int input_matches, char *matches, int nb_matches);
void not_enough_matches(map_t *map, int input_matches, char *matches,
int input_line);

#endif /* !MATCHSTICK_H_ */