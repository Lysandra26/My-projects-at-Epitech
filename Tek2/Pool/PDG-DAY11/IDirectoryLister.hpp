/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD11-lysandra.manuguerra
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
    #define IDIRECTORYLISTER_HPP_
    #include <iostream>
    #include <iomanip>
    #include <dirent.h>

class IDirectoryLister {
    public:
        bool open(const std::string &path, bool hiden);
        std::string get();
    protected:
    private:
};

#endif /* !IDIRECTORYLISTER_HPP_ */
