/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD13-lysandra.manuguerra
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
    #define ALGORITHM_HPP_
    #include <iostream>
    #include <algorithm>

template <typename T>
void swap(T &a, T &b) {
    T Temp = a;
    a = b;
    b = Temp;
}

template <typename T>
T min(T a, T b) {
    if (a < b)
        return a;
    else
    return b;
}

template <typename T>
T max(T a, T b) {
    if (b < a)
        return a;
    else
    return b;
}

template <typename T>
T clamp(T value, T min, T max) {
    if (value < min)
        return min;
    if (max < value)
        return max;
    return value;
}

#endif /* !ALGORITHM_HPP_ */
