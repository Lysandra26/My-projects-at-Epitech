/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-lysandra.manuguerra
** File description:
** ex05
*/

#include "string.h"

int length(const string_t *this)
{
    if (this->str == NULL) {
        return -1;
    }
    return strlen(this->str);
}
