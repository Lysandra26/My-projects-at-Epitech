/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** elevation_system.c
*/

#include "../../include/server.h"

int check_level4(server_t *server)
{
    ressources_t *inventory = &(server->ressource);

    if (inventory->inv[server->i][1] >= 1 &&
    inventory->inv[server->i][2] >= 1 && inventory->inv[server->i][3] >= 2 &&
    inventory->inv[server->i][5] >= 1 &&
    server->elevation.elevation_level == 3) {
        inventory->elevation_level[server->i] = 4;
        return 0;
    }
    return 1;
}

int check_level3(server_t *server)
{
    ressources_t *inventory = &(server->ressource);

    if (inventory->inv[server->i][1] >= 2 &&
    inventory->inv[server->i][5] >= 2 && inventory->inv[server->i][3] >= 1 &&
    server->elevation.elevation_level == 2) {
        inventory->elevation_level[server->i] = 3;
        return 0;
    }
    return 1;
}

int check_level2(server_t *server)
{
    ressources_t *inventory = &(server->ressource);

    if (inventory->inv[server->i][1] >= 1 &&
    inventory->inv[server->i][2] >= 1 && inventory->inv[server->i][3] >= 1 &&
    server->elevation.elevation_level == 1) {
        inventory->elevation_level[server->i] = 2;
        return 0;
    }
    return 1;
}

int check_level1(server_t *server)
{
    ressources_t *inventory = &(server->ressource);

    if (inventory->inv[server->i][1] >= 1 &&
    server->elevation.elevation_level == 0) {
        inventory->elevation_level[server->i] = 1;
        return 0;
    }
    return 1;
}

int check_elevation(server_t *server)
{
    if (check_level1(server) == 0) {
        return 0;
    }
    if (check_level2(server) == 0) {
        return 0;
    }
    if (check_level3(server) == 0) {
        return 0;
    }
    if (check_level4(server) == 0) {
        return 0;
    }
    if (check_level_2(server) == 0) {
        return 0;
    }
    return 1;
}
