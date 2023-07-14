##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Compil Programm
##

SRC =	src/IMonitorDisplay.cpp \
		src/IMonitorModule.cpp \
		TextMode/DisplayScreen.cpp \
		GraphicalMode/DisplaySfml.cpp \
		GraphicalMode/Objects.cpp \

OBJ = $(SRC:.cpp=.o)

CFLAGS = -g3 -W -Wall -Wextra

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

NAME = MyGKrellm

all: $(NAME)

$(NAME): $(OBJ)
		g++ $(OBJ) -o $(NAME) $(LDFLAGS) -lncurses

clean:
	$(RM) $(OBJ)

fclean:    clean
	$(RM) $(NAME)

re:    fclean all