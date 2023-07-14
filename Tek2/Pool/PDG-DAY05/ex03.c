/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-lysandra.manuguerra
** File description:
** ex03
*/

#include "string.h"

char func_at(const string_t *this, size_t pos)
{
    return (pos < strlen(this->str)) ? this->str[pos] : -1;
}
