/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static VertexClass *Vertex_addition(VertexClass *p1, VertexClass *p2)
{
    VertexClass *new = malloc(((Class *)(p1))->__size__);

    memcpy(new, p1, ((Class *)(p1))->__size__);
    new->x = p1->x + p2->x;
    new->y = p1->y + p2->y;
    new->z = p1->z + p2->z;

    return new;
}

static VertexClass *Vertex_substraction(VertexClass *p1, VertexClass *p2)
{
    VertexClass *new = malloc(((Class *)(p1))->__size__);

    memcpy(new, p1, ((Class *)(p1))->__size__);
    new->x = p1->x - p2->x;
    new->y = p1->y - p2->y;
    new->z = p1->z - p2->z;

    return new;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof(char) * 1000);

    snprintf(str, 1000, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    int x = va_arg((*args), int);
    int y = va_arg((*args), int);
    int z = va_arg((*args), int);

    this->x = x;
    this->y = y;
    this->z = z;
}

static void Vertex_dtor(VertexClass *this)
{
    return;
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_addition,
        .__sub__ = (binary_operator_t)&Vertex_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
