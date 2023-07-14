/*
** EPITECH PROJECT, 2023
** Day 4PM
** File description:
** int_list.c
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

typedef struct int_node_s
{
    int value;
    struct int_node_s *next ;
}   int_node_t ;

typedef int_node_t * int_list_t ;

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int size = 0;
    int_node_t *current = list;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

bool int_list_is_empty(int_list_t list)
{
    if (list->next == NULL) {
        return true;
    } else {
        return false;
    }
}
