/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** manage_commands.c
*/

#include "../../include/server.h"

void manage_player_commands(server_t *server)
{
    time_t start_time = time(NULL);

    if (!strncmp(server->buffer, "Look", 4)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        check_look(server, server->i);
    }
    if (!strncmp(server->buffer, "Inventory", 9)) {
        while (difftime(time(NULL), start_time) < 1 / server->val.frequence) {
        }
        print_player_inventory(server, server->i);
    }
    if (!strncmp(server->buffer, "Broadcast text", 14)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
    }
}

void manage_movement_commands2(server_t *server)
{
    time_t start_time = time(NULL);

    if (!strncmp(server->buffer, "Right", 5)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
        move_right(server, server->i);
        printf("\n");
        print_map(server);
    }
    if (!strncmp(server->buffer, "Left", 4)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
        move_left(server, server->i);
        printf("\n");
        print_map(server);
    }
}

void manage_movement_commands(server_t *server)
{
    time_t start_time = time(NULL);

    if (!strncmp(server->buffer, "Forward", 7)) {
        while (difftime(time(NULL), start_time) < 7 / server->val.frequence) {
        }
        dprintf(server->client_socket[server->i], "ok\r\n");
        move_forward(server, server->i);
        printf("\n");
        print_map(server);
    }
    manage_movement_commands2(server);
}

void manage_commands(server_t *server)
{
    manage_movement_commands(server);
    manage_player_commands(server);
    manage_commands2(server);
}
