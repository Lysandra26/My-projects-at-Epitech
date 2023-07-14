/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD12-lysandra.manuguerra
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
    #define PICTURE_HPP_
    #include <iostream>
    #include <iomanip>

class Picture {
    public:
        Picture(const std::string &file);
        ~Picture();
        std::string data;
        bool getPictureFromFile(const std::string &file);

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
