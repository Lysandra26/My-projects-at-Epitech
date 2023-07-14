/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-lysandra.manuguerra
** File description:
** ex02
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    size_t new_len = strlen(this->str) + strlen(ap->str);
    char *new_str = malloc(new_len + 1);
    strcpy(new_str, this->str);
    strcat(new_str, ap->str);
    free(this->str);
    this->str = new_str;
}

void append_c(string_t *this, const char *ap)
{
    size_t new_len = strlen(this->str) + strlen(ap);
    char *new_str = malloc(new_len + 1);
    strcpy(new_str, this->str);
    strcat(new_str, ap);
    free(this->str);
    this->str = new_str;
}
