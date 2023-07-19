/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** PPMWritter
*/

#ifndef PPMWRITTER_HPP_
#define PPMWRITTER_HPP_
#include "Header.hpp"

class PPMWritter {
    public:
        static void saveImage(const std::string& filename, const std::vector<Color>& imageBuffer, int width, int height);
    protected:
    private:
};

#endif /* !PPMWRITTER_HPP_ */
