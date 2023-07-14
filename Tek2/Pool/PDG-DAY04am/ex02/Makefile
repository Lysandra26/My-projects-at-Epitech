##
## EPITECH PROJECT, 2022
## Day 4AM
## File description:
## Makefile
##

SRC = concat.c \

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
