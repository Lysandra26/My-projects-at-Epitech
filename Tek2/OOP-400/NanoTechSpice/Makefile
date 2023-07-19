##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-tekspice-lysandra.manuguerra
## File description:
## Makefile
##

NAME = nanotekspice

RM = rm -rf

CC = g++

SRC =	nano.cpp \
		Parser/Parser.cpp \
		Commands/Commands.cpp \
		Error/ErrorArgument.cpp \

OBJ = $(SRC:.cpp=.o)

CXXFLAGS	+= -W -Wall -Wextra
CXXFLAGS	+= -I ./ -I src -I Parser -I Gates -I Commands -I Error -I Shell

ifeq ($(DEBUG), TRUE)
	CXXFLAGS += -g
else
	CXXFLAGS += -Werror
endif

$(NAME): $(OBJ)
	$(RM) $(NAME)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re