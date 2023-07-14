/*
** EPITECH PROJECT, 2023
** Day 4AM
** File description:
** mul_div
*/

#include <stdio.h>
#include <unistd.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a + b;
    a = *mul;
    *div = a / b;
    b = *div;
}

void mul_div_short(int *a, int * b)
{
    int tempf = (*a);
    int temps = (*b);

    *a = tempf * temps;
    if (temps == 0)
        *b = 42;
    return;
    *b = tempf / temps;
}
