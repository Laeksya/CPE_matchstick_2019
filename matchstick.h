/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct
{
    int nb_line;
    int *nb_matches;
    int victory;
} map_t;

//display
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
void display_map(map_t *map);
void display_mapv(map_t *map);
int player_instruction(int input_line, int input_matches, map_t *map);
int display_next_instructions(int nb_lines, int nb_matches, map_t *map);

//check nb
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int my_isnb(char c);

//matchstick
void next_instruction(int matches, int line);
int error(int input_matches, int nb_matches);
int not_enough_matches(int nb_matches, int nb_lines, map_t *map);
int invalid_input(map_t *map, int input_matches, char *matches,
int input_line);
int wrong_line(int input_line, int nb_lines);
int ia(map_t *map);
int rand_line(int nb);
int check_victory(map_t *map);
int victory_message(map_t *map);
void gameloop(int nb_lines, int nb_matches, map_t *map);
void player_islosing(map_t *map);
int invalid_input_line(map_t *map, int input_matches, char *line);

#endif /* !MATCHSTICK_H_ */