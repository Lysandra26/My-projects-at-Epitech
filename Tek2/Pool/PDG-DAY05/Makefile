##
## EPITECH PROJECT, 2022
## Day 5
## File description:
## Makefile
##

SRC =	ex00.c \
		ex01.c \
		ex02.c \
		ex03.c \
		ex04.c \
		ex05.c \

OBJ = $(SRC:.c=.o) \

CFLAGS = -std=gnu17 -Wextra -W -Wall -Werror -L. -lstring

all : libstring.a

libstring.a: $(OBJ)
	ar rcs libstring.a $^

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) libstring.a

re : fclean all
