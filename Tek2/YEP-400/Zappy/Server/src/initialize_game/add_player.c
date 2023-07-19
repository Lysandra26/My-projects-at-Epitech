/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** add_player.c
*/

#include "../../include/server.h"

void add_player_to_map(server_t *server)
{
    int client_x = rand() % server->val.width;
    int client_y = rand() % server->val.height;

    server->maps.prev_char = server->maps.map[client_y][client_x];
    server->val.pos_clients[server->i * 2] = client_x;
    server->val.pos_clients[server->i * 2 + 1] = client_y;
    server->maps.map[client_y][client_x] = 'J';
}
