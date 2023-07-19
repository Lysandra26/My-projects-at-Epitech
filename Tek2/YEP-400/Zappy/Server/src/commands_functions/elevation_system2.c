/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** elevation_system2.c
*/

#include "../../include/server.h"

int check_level7(server_t *server)
{
    ressources_t *inventory = &(server->ressource);

    if (inventory->inv[server->i][1] >= 2 &&
    inventory->inv[server->i][2] >= 2 && inventory->inv[server->i][3] >= 2 &&
    inventory->inv[server->i][4] >= 2 &&
    inventory->inv[server->i][5] >= 2 &&
    inventory->inv[server->i][6] >= 1 &&
    server->elevation.elevation_level == 5) {
        inventory->elevation_level[server->i] = 6;
        return 0;
    }
    return 1;
}

int check_level6(server_t *server)
{
    ressources_t *inventory = &(server->ressource);

    if (inventory->inv[server->i][1] >= 1 &&
    inventory->inv[server->i][2] >= 2 && inventory->inv[server->i][3] >= 3 &&
    inventory->inv[server->i][5] >= 1 &&
    server->elevation.elevation_level == 5) {
        inventory->elevation_level[server->i] = 5;
        return 0;
    }
    return 1;
}

int check_level5(server_t *server)
{
    ressources_t *inventory = &(server->ressource);

    if (inventory->inv[server->i][1] >= 1 &&
    inventory->inv[server->i][2] >= 2 && inventory->inv[server->i][3] >= 1 &&
    inventory->inv[server->i][4] >= 3 &&
    server->elevation.elevation_level == 4) {
        inventory->elevation_level[server->i] = 5;
        return 0;
    }
    return 1;
}

int check_level_2(server_t *server)
{
    if (check_level5(server) == 0) {
        return 0;
    }
    return 1;
}
