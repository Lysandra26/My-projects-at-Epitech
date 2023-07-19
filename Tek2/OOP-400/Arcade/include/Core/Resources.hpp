/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-arcade-edgar.falcou
** File description:
** Resources
*/

#ifndef RESOURCES_HPP_
#define RESOURCES_HPP_
#include <iostream>
#include <dlfcn.h>
#include <string>
#include <fstream>

class Utils {
    public:
        Utils();
        ~Utils();
        void *my_dlopen(std::string path);
        void my_dlclose(void *lib);

        template <typename T>
        T *my_dlsym(void *lib, std::string func)
        {
            void *function = dlsym(lib, func.c_str());
            if (function == nullptr)
                std::cerr << "ERROR dlsym : " << dlerror() << std::endl;
            auto entryPoint = reinterpret_cast<T *(*)()>(function);
            return entryPoint();
        }

    protected:
    private:
};

#endif /* !RESOURCES_HPP_ */
