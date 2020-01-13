##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile to compile  and its tests
##

NAME	=	matchstick

SRC	=	main.c			\
		display.c 		\
		get_next_line.c \
		matchstick.c

CFLAGS +=	-Wextra -Wall

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f *.gcno
		rm -f *.gcda
		rm -f vscode*

re:	fclean all

.PHONY:		all clean fclean re