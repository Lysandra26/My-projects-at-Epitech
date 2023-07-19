/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** check_values.c
*/

#include "../../include/server.h"

void check_freq_value(char *argv)
{
    int check_number_value = atoi(argv);

    if (check_number_value < 2) {
        printf("Freq should not be under 2\n");
        exit(84);
    }
}

void check_size_value(char *argv)
{
    int check_number_value = atoi(argv);

    if (check_number_value > 30) {
        printf("size is too big you can't do more than 30 in size\n");
        exit(84);
    }
}

int check_end_life(server_t *server, int j)
{
    for (j = 0; server->client_socket[j]; j++) {
        if (server->val.time_clients[j] <= 0) {
            printf("Client at index %d has reached end of life.\n", j);
            dprintf(server->client_socket[j],
            "you have reach the end of your life\r\n");
            shutdown(server->client_socket[j], SHUT_RDWR);
            return 1;
        }
        if (server->val.tab_clients[j] <= 0) {
            printf("Client at index %d has reached end of life.\n", j);
            dprintf(server->client_socket[j],
            "you have reach the end of your life\r\n");
            shutdown(server->client_socket[j], SHUT_RDWR);
            return 1;
        }
    }
    return 0;
}
