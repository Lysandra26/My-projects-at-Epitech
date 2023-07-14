/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-lysandra.manuguerra
** File description:
** string
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = malloc(strlen(s) + 1);
    strcpy(this->str, s);
}

void string_destroy(string_t *this)
{
    free(this->str);
    this->str = NULL;
}
