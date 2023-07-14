##
## EPITECH PROJECT, 2022
## Day 4PM
## File description:
## Makefile
##

SRC = int_list.c \

OBJ = $(SRC:.c=.o) \

CFLAGS = -std=gnu17 -Wextra -W -Wall -Werror

NAME = a.out

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
