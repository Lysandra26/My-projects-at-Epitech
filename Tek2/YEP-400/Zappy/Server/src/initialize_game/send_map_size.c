/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** send_map_size.c
*/

#include "../../include/server.h"

void manage_client_num(server_t *server)
{
    dprintf(server->client_socket[server->i],
    "%d\n%d %d\n", server->val.temp_nb, server->val.width, server->val.height);
    server->val.temp_nb--;
}

void send_map_size(server_t *server)
{
    manage_client_num(server);
}
