/*
** EPITECH PROJECT, 2023
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** responseToServer
*/

#include "../include/back.hpp"

void gui::Back::sendTeamName()
{
    const char* teamName = "GRAPHIC\n";
    // printf("<--GRAPHIC\n");
    send(_sock, teamName, strlen(teamName), 0);
}

void gui::Back::sendRequests()
{
    const int MAX_REQUESTS = 10;
    const char* requests[MAX_REQUESTS] = {
        "REQUEST 1",
        "REQUEST 2",
    };

    for (int i = 0; i < MAX_REQUESTS; ++i) {
        send(_sock, requests[i], strlen(requests[i]), 0);
    }
}
