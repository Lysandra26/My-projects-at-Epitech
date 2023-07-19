##
## EPITECH PROJECT, 2022
## B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
## File description:
## Makefile
##


CC = gcc

CFLAGS = -g3 -W -Wall -Wextra -c -I../include/

SRC = 	src/main.c \
		src/server.c\
		src/normes_functions.c\
		src/error_management/error_management.c\
		src/manage_commands_folder/manage_commands.c\
		src/initialize_game/attribute_values.c\
		src/error_management/check_values.c\
		src/manage_commands_folder/manage_commands2.c\
		src/manage_commands_folder/manage_gui_commands.c\
		src/commands_functions/elevation_system.c\
		src/print_help.c\
		src/initialize_game/create_map.c\
		src/initialize_game/add_player.c\
		src/print_map_test.c\
		src/commands_functions/move_functions.c\
		src/commands_functions/inventory_management.c\
		src/commands_functions/check_look.c\
		src/commands_functions/elevation_system2.c\
		src/replace_map.c\
		src/commands_functions/connect_nbr.c\
		src/initialize_game/attribute_teams.c\
		src/initialize_game/send_map_size.c\

OBJ = $(SRC:.c=.o)

TARGET = zappy_server

all: $(TARGET)

$(TARGET): $(OBJ)
		@$(CC) -o $(TARGET) $(OBJ)
		@echo "\033[1;92mBuild OK -> server\033[0m"

clean :
		@rm -rf $(OBJ)
		@echo "\033[1;92mClean OK -> server\033[0m"

fclean : clean
		@rm -rf $(TARGET)
		@echo "\033[1;92mFclean OK -> server\033[0m"

re : fclean all
