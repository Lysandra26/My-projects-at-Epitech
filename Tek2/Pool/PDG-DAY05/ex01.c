/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-lysandra.manuguerra
** File description:
** ex01
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    this->str = (char *) malloc(sizeof(char) * (strlen(str->str) + 1));
    strcpy(this->str, str->str);
}

void assign_c(string_t *this, const char *s)
{
    this->str = (char *) malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(this->str, s);
}
