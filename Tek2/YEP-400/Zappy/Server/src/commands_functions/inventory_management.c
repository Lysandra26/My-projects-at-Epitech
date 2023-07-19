/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** inventory_management.c
*/

#include "../../include/server.h"

void print_player_inventory(server_t *server, int client_index)
{
    ressources_t *inventory = &(server->ressource);

    dprintf(server->client_socket[client_index],
    "[ food %d, linemate %d, deraumere %d, ",
    inventory->inv[client_index][0], inventory->inv[client_index][1],
    inventory->inv[client_index][2]);
    dprintf(server->client_socket[client_index],
    "sibur %d, mendiane %d, phiras %d, thystame %d]\r\n",
    inventory->inv[client_index][3],
    inventory->inv[client_index][4], inventory->inv[client_index][5],
    inventory->inv[client_index][6]);
}

void call_switch_ressource(server_t *server, char ressource, int client)
{
    switch (ressource) {
        case 'M':
            server->ressource.inv[client][4]++;
            break;
        case 'P':
            server->ressource.inv[client][5]++;
            break;
        case 'T':
            server->ressource.inv[client][6]++;
            break;
        default:
            break;
    }
}

void check_ressources(server_t *server, int client_index, int x, int y)
{
    char ressource = server->maps.map[y][x];

    switch (ressource) {
        case 'F':
            server->ressource.inv[client_index][0]++;
            break;
        case 'L':
            server->ressource.inv[client_index][1]++;
            break;
        case 'D':
            server->ressource.inv[client_index][2]++;
            break;
        case 'S':
            server->ressource.inv[client_index][3]++;
            break;
        default:
            break;
    }
    call_switch_ressource(server, ressource, client_index);
}
