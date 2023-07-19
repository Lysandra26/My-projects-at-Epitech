/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** create_map.c
*/

#include "../../include/server.h"

char get_map_symbol(int resource_type);

void assign_map_symbols(server_t *server, int index, int width)
{
    int res_type = server->maps.ressources_array[index];
    server->maps.map[index / width][index % width] = get_map_symbol(res_type);
}

char get_map_symbol(int resource_type)
{
    switch (resource_type) {
        case 0:
            return 'F';
        case 1:
            return 'L';
        case 2:
            return 'D';
        case 3:
            return 'S';
        case 4:
            return 'M';
        case 5:
            return 'P';
        case 6:
            return 'T';
        default:
            return ' ';
    }
}

void create_map(server_t *server)
{
    int width = server->val.width;
    int height = server->val.height;
    int total_cases = width * height;

    server->maps.map = (char **)malloc(height * sizeof(char *));
    server->maps.ressources_array = (int *)malloc(total_cases * sizeof(int));

    for (int i = 0; i < height; i++) {
        server->maps.map[i] = (char *)malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            server->maps.map[i][j] = ' ';
        }
    }
    srand(time(NULL));
    for (int i = 0; i < total_cases; i++) {
        server->maps.ressources_array[i] = rand() % 7;
        assign_map_symbols(server, i, width);
    }
    print_map(server);
}
