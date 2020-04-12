//
// Created by rhyan on 09/04/2020.
//

#include "Enigma.h"
#include "Rotor.h"
#include <iostream>
using namespace std;

Enigma::Enigma(Rotor &leftRotor, Rotor &middleRotor, Rotor &rightRotor, Reflector &reflector) {

    this->leftRotor = &leftRotor;
    this->middleRotor = &middleRotor;
    this->rightRotor = &rightRotor;

    this->reflector = &reflector;

}

char Enigma::keyboard(char C) {
    bool rightRotorNotch = rightRotor->moveRotorNext();

    size_t posETW = ENTRY.find(toupper(C));

    size_t temp_right, temp_middle, temp_left;

    temp_right = rightRotor->outputPos(posETW);
    temp_middle = middleRotor->outputPos(temp_right);
    temp_left = leftRotor->outputPos(temp_middle);
    size_t temp_ref = reflector->reflect(temp_left);
    temp_left = leftRotor->outputPos(temp_ref, true);
    temp_middle = middleRotor->outputPos(temp_left, true);
    temp_right = rightRotor->outputPos(temp_middle, true);

    if(rightRotorNotch){
        if(middleRotor->moveRotorNext()){
            leftRotor->moveRotorNext();
        }
    }


    return ENTRY.at(temp_right);
/*
    temp_right = rightRotor->outputPos(1);
    cout << temp_right << ' ' <<  rightRotor->outputChar(temp_right) << endl;

    temp_middle = middleRotor->outputPos(temp_right);
    cout << temp_middle << ' ' <<  middleRotor->outputChar(temp_middle) << endl;

    temp_left = leftRotor->outputPos(temp_middle);
    cout << temp_left << ' ' <<  leftRotor->outputChar(temp_left) << endl;

    size_t temp_ref = reflector->reflect(temp_left);
    cout << temp_ref << ' ' << reflector->reflectChar(temp_ref) << endl;

    temp_left = leftRotor->outputPos(temp_ref, true);
    cout << temp_left << ' ' <<  leftRotor->outputChar(temp_left, true) << endl;

    temp_middle = middleRotor->outputPos(temp_left, true);
    cout << temp_middle << ' ' <<  middleRotor->outputChar(temp_middle, true) << endl;

    temp_right = rightRotor->outputPos(temp_middle, true);
    cout << temp_right << ' ' <<  rightRotor->outputChar(temp_right, true) << endl;

*/



    return 0;
}
