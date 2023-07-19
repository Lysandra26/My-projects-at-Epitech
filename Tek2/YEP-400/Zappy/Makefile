##
## EPITECH PROJECT, 2022
## B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
## File description:
## Makefile
##

gui:
		@make -C Gui
		@echo "\033[1;92mBuild Gui OK\033[0m"

ia:
		@make -C Ia
		@echo "\033[1;92mBuild Ia OK\033[0m"
Server:
		@make -C Server
		@echo "\033[1;92mBuild Server OK\033[0m"

all:
		@make -C Gui
		@make -C Ia
		@make -C Server
		@echo "\033[1;92mBuild OK\033[0m"

clean :
		@make clean -C Gui
		@make clean -C Ia
		@make clean -C Server
		@echo "\033[1;92mClean OK\033[0m"

fclean : clean
		@make fclean -C Gui
		@make fclean -C Ia
		@make fclean -C Server
		@echo "\033[1;92mFclean OK\033[0m"

re : fclean all
