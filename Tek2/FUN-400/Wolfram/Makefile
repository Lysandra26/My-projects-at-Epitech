##
## EPITECH PROJECT, 2023
## B-FUN-400-MPL-4-1-wolfram-lysandra.manuguerra
## File description:
## Makefile
##

BINARY_PATH := $(shell stack path --local-install-root)
NAME = wolfram

all:
	stack build
	cp "$(BINARY_PATH)/bin/$(NAME)-exe" ./$(NAME)

tests_run:
	stack build --test --pedantic

watch:
	stack build --test --file-watch --pedantic

clean:
	stack clean

fclean: clean
	$(RM) -r .stack-work out
	$(RM) $(NAME) stack.yaml.lock

re: fclean all