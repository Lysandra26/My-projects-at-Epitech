##
## EPITECH PROJECT, 2023
## B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
## File description:
## Makefile
##

CC 		=	g++

SRC 	=	main.cpp \
			$(wildcard Front/*.cpp) \
			$(wildcard Back/*.cpp) \

NAME	=	zappy_gui

OBJ		=	$(SRC:.cpp=.o)

LFLAGS	=	-I include/

CFLAGS	=	-Wall -Wextra -pedantic -std=c++17 -lraylib -lpthread -ldl

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:     fclean all
