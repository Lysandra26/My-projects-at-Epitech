/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** connect_nbr.c
*/

#include "../../include/server.h"

void connect_nbr(server_t *server)
{
    server->val.co_clients = 0;

    for (int i = 0; i < server->max_clients; i++) {
        if (server->client_socket[i] != 0) {
            server->val.co_clients++;
        }
    }
}
