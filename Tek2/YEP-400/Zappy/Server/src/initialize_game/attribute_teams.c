/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** attribute_teams.c
*/

#include "../../include/server.h"

void trim_string(char *str)
{
    char *start = str;
    char *end;

    while (*start && isspace((unsigned char)*start))
        ++start;
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end))
        --end;
    *(end + 1) = '\0';
    if (start != str)
        memmove(str, start, (end - start) + 2);
}

void attribute_teams(server_t *server, int client_index, int team_index)
{
    char team_name[1024];

    memset(team_name, 0, sizeof(team_name));
    if (recv(server->client_socket[client_index], team_name,
    sizeof(team_name) - 1, 0) == -1) {
        perror("recv");
        return;
    }
    team_name[sizeof(team_name) - 1] = '\0';
    trim_string(team_name);
    for (int i = 0; i < server->val.nb_clients; i++) {
        if (!strcmp(server->val.teams_name[i], team_name)) {
            team_index = i;
            break;
        }
    }
    if (team_index != -1) {
        server->val.tab_clients[client_index] = team_index;
        server->val.co_clients++;
    }
}
