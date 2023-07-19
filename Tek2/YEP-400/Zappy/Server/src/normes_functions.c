/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-gabriel.rouchon
** File description:
** norme_functions.c
*/

#include "../include/server.h"

void norme_function(server_t *server)
{
    for (server->i = 0; server->i < server->max_clients; server->i++) {
        if (server->client_socket[server->i] == 0) {
                server->client_socket[server->i] = server->new_socket;
                printf("Adding to list of sockets as %d\n" , server->i);
                attribute_teams(server, server->i, -1);
                connect_nbr(server);
                send_map_size(server);
                add_player_to_map(server);
                print_map(server);
                break;
        }
    }
}

void norme_function2(server_t *server)
{
    place_random_resources(server);
    if ((server->valread = read(server->sd , server->buffer, 1024)) == 0) {
        getpeername(server->sd, (struct sockaddr*)
        &server->address, (socklen_t*)&server->addrlen);
        printf("Host disconnect, ip %s\n", inet_ntoa(server->address.sin_addr));
        close(server->sd);
        server->client_socket[server->i] = 0;
    } else {
        server->buffer[server->valread] = '\0';
        manage_commands(server);
    }
}
