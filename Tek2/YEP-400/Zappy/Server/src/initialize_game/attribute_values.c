/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** attribute_values.c
*/

#include "../../include/server.h"

void initialize_inventory(server_t *server)
{
    for (int i = 0; i < server->val.nb_clients; i++) {
        for (int j = 0; j < 7; j++) {
            server->ressource.inv[i][j] = 0;
        }
    }
}

void attribute_values(server_t *server)
{
    server->val.tab_clients = malloc(server->val.nb_clients * sizeof(int));
    server->val.pos_clients = malloc(server->val.nb_clients * sizeof(int));
    server->val.time_clients = malloc(server->val.nb_clients * sizeof(int));
    server->val.life_units = 10;
    server->val.time_units = 1260;
    server->limits.end_life = 1;

    initialize_inventory(server);
    for (int i = 0; i < server->val.nb_clients; i++) {
        server->val.tab_clients[i] = server->val.life_units;
        server->val.time_clients[i] = server->val.time_units;
    }
}
