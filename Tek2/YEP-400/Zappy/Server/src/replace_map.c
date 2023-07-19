/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** replace_map.c
*/

#include "../include/server.h"

#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time()

void switch_part3(char **map, int i, int j, int random_value)
{
    switch (random_value) {
        case 80 ... 89:
            map[i][j] = 'M';
            break;
        case 90 ... 94:
            map[i][j] = 'P';
            break;
        default:
            map[i][j] = 'T';
            break;
    }
}

void switch_part2(char **map, int i, int j, int random_value)
{
    switch (random_value) {
        case 0 ... 19:
            map[i][j] = 'F';
            break;
        case 20 ... 39:
            map[i][j] = 'L';
            break;
        case 40 ... 59:
            map[i][j] = 'D';
            break;
        case 60 ... 79:
            map[i][j] = 'S';
            break;
        default:
            switch_part3(map, i, j, random_value);
            break;
    }
}

void switch_part(char **map, int i, int j)
{
    int random_value = 0;

    if (map[i][j] == ' ') {
        random_value = rand() % 100;
        switch_part2(map, i, j, random_value);
    }
}

void place_random_resources(server_t *server)
{
    int width = server->val.width;
    int height = server->val.height;
    char **map = server->maps.map;
    int i, j;

    srand(time(NULL));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            switch_part(map, i, j);
        }
    }
}
