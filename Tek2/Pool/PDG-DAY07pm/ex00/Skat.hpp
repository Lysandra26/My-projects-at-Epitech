/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD07pm-lysandra.manuguerra
** File description:
** Skat
*/

#ifndef SKAT_HPP_
    #define SKAT_HPP_
    #include <iostream>
    #include <iomanip>

class Skat
{
public:
    Skat( const std::string &name, int stimPaks);
    ~ Skat();

    [...] stimPaks();
    const std :: string &name();
    void shareStimPaks(int number, [...] stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();

private:
    [...]
};

#endif /* !SKAT_HPP_ */
