/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** check_look.c
*/

#include "../../include/server.h"

void print_look(server_t *server, int client_index)
{
    dprintf(server->client_socket[client_index], "Resources:\n");
    dprintf(server->client_socket[client_index], "Right: %c\n",
    server->lok.right_ressource);
    dprintf(server->client_socket[client_index], "Left: %c\n",
    server->lok.left_ressource);
    dprintf(server->client_socket[client_index], "Forward: %c\n",
    server->lok.for_ressource);
}

char check_for(server_t *server, int x, int y)
{
    char forward_ressource = server->maps.map[y][x];

    return forward_ressource;
}

char check_lef(server_t *server, int x, int y)
{
    char left_ressource = server->maps.map[y][x];

    return left_ressource;
}

char check_right(server_t *server, int x, int y)
{
    char right_ressource = server->maps.map[y][x];

    return right_ressource;
}

void check_look(server_t *server, int client_index)
{
    int x = server->val.pos_clients[client_index * 2];
    int y = server->val.pos_clients[client_index * 2 + 1];
    int width = server->val.width;
    int height = server->val.height;

    server->lok.right_ressource = check_right(server, (x + 1) % width, y);
    server->lok.left_ressource = check_lef(server,  (x - 1 + width) % width, y);
    server->lok.for_ressource = check_for(server, x, (y - 1 + height) % height);
    print_look(server, client_index);
}
