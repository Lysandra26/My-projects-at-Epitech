##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-edgar.falcou
## File description:
## Makefile
##

CC		= g++

NAME	= ../../../lib/arcade_ncurses.so

SRC		=	Ncurses.cpp \

OBJ		= $(SRC:.cpp=.o)

FLAGS 		= -W -Wall -Wextra -fPIC -std=c++14 -I ../../../include/Libs/NCURSES

LDFLAGS		+= -shared -lstdc++ -lncurses

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re