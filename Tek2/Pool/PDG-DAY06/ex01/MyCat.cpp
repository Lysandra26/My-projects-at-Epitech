/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD06-lysandra.manuguerra
** File description:
** MyCat
*/

#include <iostream>
#include <fstream>
#include <string>

class MyCat {
public:
    MyCat(int argc, char* argv[])
    {
        if (argc == 1) {
            std::string line;
            while (std::getline(std::cin, line))
                std::cout << line << std::endl;
        }
        for (int i = 1; i < argc; i++) {
            std::ifstream file(argv[i]);
            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line))
                    std::cout << line << std::endl;
                file.close();
            } else {
                std::cerr << "MyCat: " << argv[i] << ": No such file or directory" << std::endl;
                exit(84);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    MyCat obj (argc, argv);
    return 0;
}
