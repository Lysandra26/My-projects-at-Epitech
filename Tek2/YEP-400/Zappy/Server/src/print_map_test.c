/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** print_map_test.c
*/

#include "../include/server.h"

void print_map(server_t *server)
{
    int width = server->val.width;
    int height = server->val.height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", server->maps.map[i][j]);
        }
        printf("\n");
    }
}
