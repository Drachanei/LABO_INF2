//
// Created by rhyan on 09/04/2020.
//

#include "Enigma.h"
#include "Rotor.h"
#include <iostream>
using namespace std;

Enigma::Enigma(Rotor &leftRotor, Rotor &middleRotor, Rotor &rightRotor, Reflector &reflector) :
leftRotor(leftRotor), middleRotor(middleRotor), rightRotor(rightRotor), reflector(reflector){
}

char Enigma::convert(char C, bool debug) {
    bool rightRotorNotch = rightRotor.moveRotorNext();

    size_t posETW = ENTRY.find(toupper(C));

    size_t leftOutput, middleOutput, rightOutput,
            leftOutput_R, middleOutput_R, rightOutput_R;





    rightOutput = rightRotor.outputPos(posETW);
    middleOutput = middleRotor.outputPos(rightOutput);
    leftOutput = leftRotor.outputPos(middleOutput);

    size_t temp_ref = reflector.reflect(leftOutput);

    leftOutput_R = leftRotor.outputPos(temp_ref, true);
    middleOutput_R = middleRotor.outputPos(leftOutput_R, true);
    rightOutput_R = rightRotor.outputPos(middleOutput_R, true);

    if(rightRotorNotch){
        if(middleRotor.moveRotorNext()){
            leftRotor.moveRotorNext();
        }
    }


    if(debug){
        char temp = C;
        rightRotor.getRotorConfig();
        cout << "result         : " << "[" << rightRotor.outputChar(rightOutput) << " <= " <<
        rightRotor.outputChar(rightOutput, true) << "] <= " << temp << endl << endl;

        middleRotor.getRotorConfig();
        cout << "result         : " << "[" << middleRotor.outputChar(middleOutput) << " <= " <<
        middleRotor.outputChar(middleOutput, true) << "] <= " << temp << endl << endl;

        leftRotor.getRotorConfig();
        cout << "result         : " << "[" << leftRotor.outputChar(leftOutput) << " <= " << leftRotor.outputChar(leftOutput, true) << "] <= " << temp << endl << endl;

        reflector.getReflectorConfig();
        cout << "result         : " << "[" << reflector.outputChar(leftOutput) << " <= " << reflector.outputChar(leftOutput, true) << "]" << endl;
    }

    return ENTRY.at(rightOutput_R);
}


void Enigma::getConfig() {
    cout << "CONFIGURATION SIMPLE" << endl << endl;
    cout << "LEFT rotor" << endl;
    leftRotor.getRotorConfig();
    cout << "MIDDLE rotor" << endl;
    middleRotor.getRotorConfig();
    cout << "RIGHT rotor" << endl;
    rightRotor.getRotorConfig();
    cout << "Reflector" << endl;
    reflector.getReflectorConfig();
    cout << endl;
}
