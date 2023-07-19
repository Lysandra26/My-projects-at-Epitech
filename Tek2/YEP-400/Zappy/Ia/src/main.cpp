/*
** EPITECH PROJECT, 2023
** Ia
** File description:
** main
*/

#include "../include/ia.hpp"

int error_msg(int ret)
{
    std::cout
    << "USAGE: ./zappy_ai -p port -n name -h machine\n"
       "\tport is the port number\n"
       "\tname is the name of the team\n"
       "\tmachine is the name of the machine; localhost by default\n";
    return (ret);
}

int check_args(char *first_arg, char *second_arg, int *port, char **name)
{
    if (std::string(first_arg) == "-p") {
        if ((*port = atoi(second_arg)) == 0)
            return (1);
    } else if (std::string(first_arg) == "-n") {
        if ((*name = second_arg) == NULL)
            return (1);
    }
     return (0);
}

int start_ai(int port, char *name, char *machine, int id)
{
    AI player_bot(port, name, machine, id);

    player_bot.connect_to_server();
    player_bot.setup_bot();
    player_bot.set_nb_bot(id);
    player_bot.run();
    return (0);
}

int setup_args(char **argv)
{
    int port;
    char *name;
    char *machine = NULL;

    for (int i = 1; argv[i]; i++) {
        if (check_args(argv[i], argv[i + 1], &port, &name) != 0)
            return (error_msg(84));
        if (std::string(argv[i]) == "-h" && argv[i + 1] != NULL) {
            machine = argv[i + 1];
        }
    }
    return (start_ai(port, name, machine, 1));
}

int main(int argc, char **argv)
{
    if (argc <= 4) {
        if (std::string(argv[1]) == "-help")
            return (error_msg(0));
        else
            return (error_msg(84));
    }
    return (setup_args(argv));
}
