##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-edgar.falcou
## File description:
## Makefile
##

CXX 	= g++

INC = -I include/Core/

CXXFLAGS    +=    -Wall -Wextra -pedantic -std=c++17 -fPIC $(INC)

LDFLAGS		=	-ldl

MAKE	= make

NAME		=	arcade

SRC		=	src/Core/Resources.cpp \
			src/Core/Core.cpp \
			src/Core/Main.cpp \
			src/Core/Highscore.cpp \

OBJ		=	$(SRC:.cpp=.o)

all:	sdl ncurses sfml nibbler snake core

$(NAME):		$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

core: $(NAME)

games: nibbler snake

graphicals: sdl ncurses sfml

sdl:
	$(MAKE) -C ./src/Libs/SDL2

ncurses:
	$(MAKE) -C ./src/Libs/NCURSES

sfml:
	$(MAKE) -C ./src/Libs/SFML

nibbler:
	$(MAKE) -C ./src/Games/Nibbler

snake:
	$(MAKE) -C ./src/Games/Snake

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./src/Libs/SDL2
	$(MAKE) clean -C ./src/Libs/NCURSES
	$(MAKE) clean -C ./src/Libs/SFML
	$(MAKE) clean -C ./src/Games/Nibbler
	$(MAKE) clean -C ./src/Games/Snake

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./src/Libs/SDL2
	$(MAKE) fclean -C ./src/Libs/NCURSES
	$(MAKE) fclean -C ./src/Libs/SFML
	$(MAKE) fclean -C ./src/Games/Nibbler
	$(MAKE) fclean -C ./src/Games/Snake

re:	fclean all

.PHONY:	all core sdl ncurses sfml snake nibbler clean fclean re