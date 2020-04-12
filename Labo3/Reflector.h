//
// Created by rhyan on 09/04/2020.
//

#ifndef LABO3_REFLECTOR_H
#define LABO3_REFLECTOR_H

#include "string"
#include "vector"


class Reflector {

public:
    size_t reflect(size_t pos);
    char reflectChar(size_t pos);


private:
    unsigned reflectorId = 1;
    const std::string ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const std::vector<std::string> REFLECTOR_WIRING = {
            "EJMZALYXVBWFCRQUONTSPIKHGD",
            "YRUHQSLDPXNGOKMIEBFZCWVJAT",
            "FVPJIAOYEDRZXWGCTKUQSBNMHL"
    };

    std::string wiring = REFLECTOR_WIRING.at(reflectorId);
};


#endif //LABO3_REFLECTOR_H
