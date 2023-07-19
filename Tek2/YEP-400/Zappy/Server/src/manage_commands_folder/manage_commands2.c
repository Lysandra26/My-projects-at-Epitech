/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** manage_commands2.c
*/

#include "../../include/server.h"

void go_to_check(server_t *server)
{
    if (check_elevation(server) == 0) {
        dprintf(server->client_socket[server->i],
        "Elevation underway\nCurrent level: %d\r\n",
        server->ressource.elevation_level[server->i]);
    } else {
        dprintf(server->client_socket[server->i], "ko\r\n");
    }
}

void manage_interactions_commands(server_t *server)
{
    time_t start_time = time(NULL);

    if (!strncmp(server->buffer, "Take object", 11)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
    }
    if (!strncmp(server->buffer, "Set object", 10)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
    }
    if (!strncmp(server->buffer, "Incantation", 11)) {
        while (difftime(time(NULL), start_time) < 300 / server->val.frequence) {
        }
        go_to_check(server);
    }
}

void manage_info_commands(server_t *server)
{
    time_t start_time = time(NULL);

    if (!strncmp(server->buffer, "Connect_nbr", 11)) {
        while (difftime(time(NULL), start_time) < 0 / server->val.frequence) {
        }
        connect_nbr(server);
        dprintf(server->client_socket[server->i],
        "%d\r\n", server->val.co_clients);
    }
    if (!strncmp(server->buffer, "Fork", 4)) {
        while (difftime(time(NULL), start_time) < 42 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
    }
    if (!strncmp(server->buffer, "Eject", 5)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
    }
}

void manage_commands2(server_t *server)
{
    manage_info_commands(server);
    manage_interactions_commands(server);
}
