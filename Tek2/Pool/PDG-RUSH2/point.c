/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static PointClass *Point_addition(PointClass *p1, PointClass *p2)
{
    PointClass *new = malloc(((Class *)(p1))->__size__);

    memcpy(new, p1, ((Class *)(p1))->__size__);
    new->x = p1->x + p2->x;
    new->y = p1->y + p2->y;

    return new;
}

static PointClass *Point_substraction(PointClass *p1, PointClass *p2)
{
    PointClass *new = malloc(((Class *)(p1))->__size__);

    memcpy(new, p1, ((Class *)(p1))->__size__);
    new->x = p1->x - p2->x;
    new->y = p1->y - p2->y;

    return new;
}

static char *Point_str(PointClass *this)
{
    char *str = malloc(sizeof(char) * 1000);

    snprintf(str, 1000, "<Point (%d, %d)>", this->x, this->y);
    return (str);
}

static void Point_ctor(PointClass *this, va_list *args)
{
    int x = va_arg((*args), int);
    int y = va_arg((*args), int);

    this->x = x;
    this->y = y;
}

static void Point_dtor(PointClass *this)
{
    return;
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_addition,
        .__sub__ = (binary_operator_t)&Point_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
