/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-raytracer-lysandra.manuguerra
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_
    #include <iostream>
    #include <libconfig.h++>

class Parsing {
    public:
        Parsing(const std::string& filename) {
            try {
                config.readFile(filename.c_str());
            } catch (const libconfig::FileIOException& fioex) {
                std::cerr << "Error reading the file" << std::endl;
                throw;
            } catch (const libconfig::ParseException& pex) {
                std::cerr << "Error parsing the file at line " << pex.getLine() << ": " << pex.getError() << std::endl;
                throw;
            }
        }

        void parseScene() {
            const libconfig::Setting& root = config.getRoot();
            const libconfig::Setting& camera = root["camera"];
            const libconfig::Setting& primitives = root["primitives"];
            const libconfig::Setting& lights = root["lights"];

            // Parse the settings
            parseCamera(camera);
            parsePrimitives(primitives);
            parseLights(lights);
        }
    private:
        libconfig::Config config;

        void parseCamera(const libconfig::Setting& cameraSetting);

        void parsePrimitives(const libconfig::Setting& primitivesSetting) {
        }

        void parseLights(const libconfig::Setting& lightsSetting) {
        }
};

#endif /* !PARSING_HPP_ */
