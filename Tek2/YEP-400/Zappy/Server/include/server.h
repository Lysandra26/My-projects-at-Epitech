/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myteams-gabriel.rouchon
** File description:
** server.h
*/

#ifndef SERVER
    #define SERVER
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <string.h>
    #include <errno.h>
    #include <arpa/inet.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/time.h>
    #include <stdbool.h>
    #include <time.h>
    #include <ctype.h>
    #define TRUE 1
    #define FALSE 0

typedef struct look_s {
    char right_ressource;
    char left_ressource;
    char for_ressource;
} look_t;

typedef struct map_s {
    char **map;
    char prev_char;
    int *ressources_array;
} map_t;

typedef struct elevation_s {
    int elevation_state;
    int elevation_level;
} elevation_t;

typedef struct ressources_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    int inv[1024][7];
    int elevation_level[1024];
} ressources_t;

typedef struct limits_s {
    int count_clients;
    bool end_life;
} limits_t;

typedef struct values_s {
    int frequence;
    int nb_clients;
    int temp_nb;
    int *tab_clients;
    int *inv_player;
    int *time_clients;
    int *pos_clients;
    int time_units;
    int life_units;
    int port;
    int width;
    int height;
    char **teams_name;
    int co_clients;
} values_t;

typedef struct server_s {
    look_t lok;
    elevation_t elevation;
    limits_t limits;
    values_t val;
    ressources_t ressource;
    map_t maps;
    int opt;
    int master_socket;
    int addrlen;
    int new_socket;
    int client_socket[1024];
    int max_clients;
    int act;
    int i;
    int valread;
    int sd;
    int max_sd;
    struct sockaddr_in address;
    char buffer[1025];
    fd_set readfds;
    char *message;
} server_t;

int init_server(server_t *server);
int error_management(int argc);
int check_str_number(const char *str);
void attribute_values(server_t *server);
void norme_function2(server_t *server);
void norme_function(server_t *server);
void manage_commands(server_t *server);
int check_end_life(server_t *server, int j);
void manage_commands2(server_t *server);
int check_elevation(server_t *server);
void print_help(void);
void create_map(server_t *server);
void add_player_to_map(server_t *server);
void print_map(server_t *server);
void move_forward(server_t *server, int client_index);
void move_right(server_t *server, int client_index);
void move_left(server_t *server, int client_index);
void check_ressources(server_t *server, int client_index, int x, int y);
void print_player_inventory(server_t *server, int client_index);
void check_look(server_t *server, int client_index);
void check_size_value(char *argv);
void check_freq_value(char *argv);
int check_level_2(server_t *server);
void place_random_resources(server_t *server);
void connect_nbr(server_t *server);
void attribute_teams(server_t *server, int client_index, int team_index);
void initialize_teams(server_t *server, char** argv, int num_teams);
void send_map_size(server_t *server);
void manage_client_num(server_t *server);

#endif /* SERVEUR */
