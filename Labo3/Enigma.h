//
// Created by rhyan on 09/04/2020.
//

#ifndef LABO3_ENIGMA_H
#define LABO3_ENIGMA_H

#include <vector>
#include <string>

#include "Rotor.h"
#include "Reflector.h"


class Enigma {
public:
    /** ---------------- Constructeur ---------------- **/
    Enigma(){};
    Enigma(Rotor& leftRotor, Rotor& middleRotor, Rotor& rightRotor, Reflector& reflector);

    char keyboard(char C);



private:
    Rotor *leftRotor, *middleRotor, *rightRotor;
    Reflector *reflector;

    const std::string ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


};


#endif //LABO3_ENIGMA_H
