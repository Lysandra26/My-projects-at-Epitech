/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "raise.h"
#include "point.h"
#include "vertex.h"

Object *new(const Class *class, ...)
{
    Object *new_obj;
    va_list ap;

    if (class == NULL || class->__size__ <= 0)
        raise("Error");
    new_obj = malloc(class->__size__);
    if (!new_obj)
        raise("Error");
    memcpy(new_obj, class, class->__size__);
    if (class && class->__ctor__) {
        va_start(ap, class);
        class->__ctor__(new_obj, &ap);
        va_end(ap);
    } else
        raise("No class or Constructor fonction exist.");
    return new_obj;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *new_obj;

    if (class == NULL || class->__size__ <= 0)
        raise("Error");
    new_obj = malloc(class->__size__);
    if (!new_obj)
        raise("Error");
    memcpy(new_obj, class, class->__size__);
    if (class && class->__ctor__) {
        class->__ctor__(new_obj, ap);
    } else
        raise("No class or Constructor fonction exist.");
    return new_obj;
}

void delete(Object *ptr)
{
    if (ptr && ((Class *)(ptr))->__dtor__) {
        ((Class *)(ptr))->__dtor__(ptr);
        free(ptr);
    }
}
