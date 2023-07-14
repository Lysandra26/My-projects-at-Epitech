/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD11-lysandra.manuguerra
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
    #define DIRECTORYLISTER_HPP_
    #include "IDirectoryLister.hpp"

class DirectoryLister {
    public:
        ~DirectoryLister();
    protected:
        DirectoryLister();
        DirectoryLister(const std::string &path, bool hidden);
    private:
};

#endif /* !DIRECTORYLISTER_HPP_ */
