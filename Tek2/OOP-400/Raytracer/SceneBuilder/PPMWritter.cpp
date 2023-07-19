/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** PPMWritter
*/

#include "Header.hpp"

void PPMWriter::saveImage(const std::string& filename, const std::vector<Color>& imageBuffer, int width, int height) {
    std::ofstream outputFile(filename);

    outputFile << "P3\n" << width << ' ' << height << "\n255\n";

    for (const auto& color : imageBuffer) {
        outputFile << static_cast<int>(color.r) << ' '
                   << static_cast<int>(color.g) << ' '
                   << static_cast<int>(color.b) << '\n';
    }
    outputFile.close();
}

