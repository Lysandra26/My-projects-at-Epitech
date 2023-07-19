/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** manage_gui_commands.c
*/

#include "../../include/server.h"

void manage_gui_commands(server_t *server)
{
    if (!strncmp(server->buffer, "msz", 3)) {
        dprintf(server->client_socket[server->i], "msz %d %d\r\n",
        server->val.width, server->val.height);
    }
}

void check_gui_commands(server_t *server)
{
    manage_gui_commands(server);
}
