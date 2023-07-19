/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** server.c
*/

#include "../include/server.h"

void continue_server4(server_t *server)
{
    for (server->i = 0; server->i < server->max_clients; server->i++) {
        server->sd = server->client_socket[server->i];
        if (FD_ISSET(server->sd , &server->readfds)) {
            norme_function2(server);
        }
    }
}

void continue_server3(server_t *server)
{
    if (FD_ISSET(server->master_socket, &server->readfds)) {
        if ((server->new_socket = accept(server->master_socket,\
        (struct sockaddr *)&server->address,\
        (socklen_t*)&server->addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("New connection , socket fd is %d , ip is : %s , port : %d \n",
        server->new_socket, inet_ntoa(server->address.sin_addr),
        ntohs(server->address.sin_port));
        dprintf(server->new_socket, "WELCOME\r\n");
        norme_function(server);
    }
    continue_server4(server);
}

void continue_server2(server_t *server)
{
    int max_sd = 0;

    while (1) {
        FD_ZERO(&server->readfds);
        FD_SET(server->master_socket, &server->readfds);
        server->max_sd = server->master_socket;
        for (server->i = 0 ; server->i < server->max_clients ; server->i++) {
            server->sd = server->client_socket[server->i];
            server->sd > 0 ? FD_SET(server->sd , &server->readfds) : 0;
            (server->sd > server->max_sd) ? server->max_sd = server->sd : 0;
        }
        max_sd = server->max_sd;
        server->act = select(max_sd + 1, &server->readfds, NULL, NULL, NULL);
        (server->act < 0) && (errno != EINTR) ? printf("select error") : 0;
        continue_server3(server);
    }
}

void continue_server(server_t *server)
{
    if (bind(server->master_socket, (struct sockaddr *)&server->address,\
        sizeof(server->address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", server->val.port);
    if (listen(server->master_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    server->addrlen = sizeof(server->address);
    puts("Waiting for connections ...");
    continue_server2(server);
}

int init_server(server_t *server)
{
    server->max_clients = 30;
    server->opt = TRUE;

    for (server->i = 0; server->i < server->max_clients; server->i++) {
        server->client_socket[server->i] = 0;
    }
    if ((server->master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server->master_socket, SOL_SOCKET, SO_REUSEADDR,
    (char *) &server->opt, sizeof(server->opt)) < 0 ) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(server->val.port);
    continue_server(server);
    return 0;
}
