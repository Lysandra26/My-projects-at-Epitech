##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-edgar.falcou
## File description:
## Makefile
##

CC		= g++

INC += -I ../../../include/Libs/SFML/


NAME		= ../../../lib/arcade_sfml.so

SRC		= 	Sfml.cpp \

OBJ		= $(SRC:.cpp=.o)

FLAGS 		= -W -Wall -Wextra -fPIC -std=c++14 $(INC)

LDFLAGS		+= -shared -lstdc++ -ldl -lsfml-graphics

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