/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** move_functions.c
*/

#include "../../include/server.h"

void move_forward(server_t *server, int client_index)
{
    int height = server->val.height;
    int x = server->val.pos_clients[client_index * 2];
    int y = server->val.pos_clients[client_index * 2 + 1];
    int new_y = (y - 1 + height) % height;

    check_ressources(server, client_index, x, new_y);
    server->maps.map[y][x] = ' ';
    server->maps.map[new_y][x] = 'J';
    server->val.pos_clients[client_index * 2 + 1] = new_y;
    print_map(server);
}

void move_left(server_t *server, int client_index)
{
    int width = server->val.width;
    int x = server->val.pos_clients[client_index * 2];
    int y = server->val.pos_clients[client_index * 2 + 1];
    int new_x = (x - 1 + width) % width;

    check_ressources(server, client_index, new_x, y);
    server->maps.map[y][x] = ' ';
    server->maps.map[y][new_x] = 'J';
    server->val.pos_clients[client_index * 2] = new_x;
    print_map(server);
}

void move_right(server_t *server, int client_index)
{
    int width = server->val.width;
    int x = server->val.pos_clients[client_index * 2];
    int y = server->val.pos_clients[client_index * 2 + 1];
    int new_x = (x + 1) % width;

    check_ressources(server, client_index, new_x, y);
    server->maps.map[y][x] = ' ';
    server->maps.map[y][new_x] = 'J';
    server->val.pos_clients[client_index * 2] = new_x;
    print_map(server);
}
