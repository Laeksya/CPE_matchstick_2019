##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile to compile  and its tests
##

NAME	=	matchstick

SRC	=	my_printf/my_strlen.c		 		\
		my_printf/my_put_nbr.c				\
		my_printf/my_putchar.c				\
		my_printf/my_putstr.c				\
		my_printf/my_putnbr_base.c 			\
		my_printf/my_putnbr_unsigned.c   	\
		my_printf/my_putnbr_base_unsigned.c \
		my_printf/function_for_printf2.c 	\
		my_printf/function_for_printf1.c    \
		my_printf/my_printf.c				\
		main.c				\
		error_handling.c	\
		display.c 			\
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
		rm -f *.vscode

re:	fclean all

.PHONY:		all clean fclean re