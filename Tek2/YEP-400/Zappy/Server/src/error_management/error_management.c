/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-zappy-gabriel.rouchon
** File description:
** error_management.c
*/

#include "../../include/server.h"


int check_str_number(const char *str)
{
    if (str == NULL) {
        exit (84);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            printf("please put only numbers inside -p -x -y -c -f field.\n");
            exit (84);
        }
    }
    return 0;
}

int error_management(int argc)
{
    if (argc < 10) {
        printf("error too less arguments.\n");
        exit(84);
    }
    return 0;
}
