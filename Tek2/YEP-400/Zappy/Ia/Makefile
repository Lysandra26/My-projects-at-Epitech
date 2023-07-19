##
## EPITECH PROJECT, 2022
## B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
## File description:
## Makefile
##

CC	=	g++

SRC	=	src/main.cpp	\
		src/ia.cpp	\
		src/handle_client.cpp	\
		src/inventory.cpp	\
		src/incantation.cpp	\
		src/environment.cpp	\
		src/reproduction.cpp	\


NAME    =       zappy_ai

OBJ     =       $(SRC:.cpp=.o)

CFLAGS  =       -Werror -W -Wall -Wextra -std=c++2a

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:     fclean all
