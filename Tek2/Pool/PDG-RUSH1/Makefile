##
## EPITECH PROJECT, 2023
## B-PDG-300-MPL-3-1-PDGRUSH1-lysandra.manuguerra
## File description:
## Makefile
##

NAME    =    pushswap_checker

SRC     =    pushswap_checker.hs

OBJ     =    $(SRC:.hs=.o)
HI      =    $(SRC:.hs=.hi)

all     :
	ghc $(CFLAGS) -o $(NAME) $(SRC)

clean   :
	rm -f $(OBJ) $(HI)

fclean    :    clean
	rm -f $(NAME)

re      :    fclean all

.PHONY  :    all clean fclean re
