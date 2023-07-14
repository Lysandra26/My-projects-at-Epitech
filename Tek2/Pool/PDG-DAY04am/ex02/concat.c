/*
** EPITECH PROJECT, 2023
** Day 4AM
** File description:
** concat
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_struct(concat_t *str)
{
    size_t len1 = strlen(str->str1);
    size_t len2 = strlen(str->str2);

    str->res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    strcpy(str->res, str->str1);
    strcat(str->res, str->str2);
}

void concat_strings(const char *str1, const char *str2, char ** res)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    *res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    strcpy(*res, str1);
    strcat(*res, str2);
}
