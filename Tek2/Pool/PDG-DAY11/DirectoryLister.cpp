/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD11-lysandra.manuguerra
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister()
{
}

DirectoryLister::~DirectoryLister()
{
}

bool DirectoryLister::open()
{

}

bool DirectoryLister::get()
{
    
}

int main (void)
{
    DirectoryLister dl("./test/", true);
    for (std::string file = dl.get(); !file.empty(); file = dl.get ())
        std::cout << file << std::endl;
    dl.open("invalid path", true);
    if (dl.open("./test/", false) == true)
        for (std::string file = dl.get(); !file.empty(); file = dl.get())
            std::cout << file << std::endl;
    return 0;
}