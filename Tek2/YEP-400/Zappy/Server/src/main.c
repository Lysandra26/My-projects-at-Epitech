/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** main.c
*/

#include "../include/server.h"

int manage_teams(char **argv, server_t *server, int i)
{
    int num_teams = 0;
    int j;

    for (j = i; argv[j] != NULL && strcmp(argv[j], "-c") != 0; j++) {
        num_teams++;
    }
    server->val.teams_name = malloc((num_teams + 1) * sizeof(char*));
    for (j = 0; strcmp(argv[i], "-c") != 0; j++) {
        server->val.teams_name[j] = strdup(argv[i]);
        i++;
    }
    server->val.teams_name[j] = NULL;
    return 0;
}

int values_attribution2(char **argv, server_t *server, int i)
{
    if (!strcmp(argv[i], "-c")) {
        check_str_number(argv[i + 1]);
        server->val.nb_clients = atoi(argv[i + 1]);
        server->val.temp_nb = server->val.nb_clients;
        attribute_values(server);
    }
    if (!strcmp(argv[i], "-f")) {
        check_str_number(argv[i + 1]);
        check_freq_value(argv[i + 1]);
        server->val.frequence = atoi(argv[i + 1]);
    }
    return 0;
}

int values_attribution(char **argv, server_t *server)
{
    for (int i = 0; argv[i]; i++) {
        if (!strcmp(argv[i], "-p")) {
            check_str_number(argv[i + 1]);
            server->val.port = atoi(argv[i + 1]);
        }
        if (!strcmp(argv[i], "-x")) {
            check_str_number(argv[i + 1]);
            check_size_value(argv[i + 1]);
            server->val.width = atoi(argv[i + 1]);
        }
        if (!strcmp(argv[i], "-y")) {
            check_str_number(argv[i + 1]);
            check_size_value(argv[i + 1]);
            server->val.height = atoi(argv[i + 1]);
        }
        if (!strcmp(argv[i], "-n"))
            manage_teams(argv, server, i + 1);
        values_attribution2(argv, server, i);
    }
    return 0;
}

server_t *init_struct(int argc, char **argv)
{
    server_t *server = malloc(sizeof(server_t));

    values_attribution(argv, server);
    error_management(argc);
    create_map(server);
    init_server(server);
    return server;
}

int main(int argc, char **argv)
{
    if (argc < 10) {
        print_help();
        exit(84);
    }
    init_struct(argc, argv);
    return 0;
}
