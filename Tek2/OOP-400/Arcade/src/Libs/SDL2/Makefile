##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-edgar.falcou
## File description:
## Makefile
##

CC		= g++

INC += -I ../../../include/Libs/SDL2/


NAME		= ../../../lib/arcade_sdl2.so

SRC		= 	SDL2.cpp \

OBJ		= $(SRC:.cpp=.o)

FLAGS 		= -W -Wall -Wextra -fPIC -std=c++14 $(INC)

LDFLAGS		+= -shared -lstdc++ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

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