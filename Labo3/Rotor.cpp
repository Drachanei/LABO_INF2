//
// Created by rhyan on 24/03/2020.
//

#include "Rotor.h"
#include <iostream>

using namespace std;

void Rotor::setRotorId(unsigned id) {
    this->rotorId = id;
    this->wiring = ROTOR_WIRINGS.at(id - 1);
    this->currentEntry = ENTRY;
    this->notch = ROTOR_NOTCH.at(id - 1);
}

void Rotor::setRotorPosition(char position) {

    wiring = ROTOR_WIRINGS.at(rotorId - 1);
    currentEntry = ENTRY;

    currentPos = ENTRY.find(toupper(position));

    rotate(wiring.begin(), wiring.begin() + currentPos, wiring.end());
    rotate(currentEntry.begin(), currentEntry.begin() + currentPos, currentEntry.end());
}

std::string Rotor::getRotorId() {
    string id;
    switch (rotorId){
        case 1:
            id = "I";
            break;
        case 2:
            id = "II";
            break;
        case 3:
            id = "III";
            break;
        case 4:
            id = "IV";
            break;
        case 5:
            id = "V";
            break;
        default:
            id = "undef";
    };

    return id;
}

void Rotor::getRotorConfig() {

    cout << "rotor id       : " << getRotorId() << endl;
    cout << "entry          : " << ENTRY << endl;
    cout << "wiring         : " << ROTOR_WIRINGS.at(rotorId - 1) << endl;
    cout << "notch          : " << notch << endl;
    cout << "poisition      : " << currentEntry.front() << endl;
}




bool Rotor::moveRotorNext() {
    rotate(wiring.begin(), wiring.begin() + 1, wiring.end());
    rotate(currentEntry.begin(), currentEntry.begin() + 1, currentEntry.end());

    return notch == currentEntry.front();
}

size_t Rotor::outputPos(size_t position, bool r) {
    if(r){
        return wiring.find(currentEntry.at(position));
    }
    return currentEntry.find(wiring.at(position));
}

char Rotor::outputChar(size_t position, bool r) {
    if(r){
        size_t pos = wiring.find(currentEntry.at(position));
        return currentEntry.at(pos);
    }
    return currentEntry.at(position);
}

char Rotor::getRotorPos() {
    return currentEntry.front();
}




