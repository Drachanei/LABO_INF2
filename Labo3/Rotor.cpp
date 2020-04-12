//
// Created by rhyan on 24/03/2020.
//

#include "Rotor.h"
#include <iostream>

using namespace std;

void Rotor::getRotorId() {
    cout << "rotor id : " << rotorId;
}

void Rotor::setRotorId(unsigned id) {
    this->rotorId = id;
    this->wiring = ROTOR_WIRINGS.at(id - 1);
    this->currentEntry = ENTRY;
    this->notch = ROTOR_NOTCH.at(id - 1);
}

void Rotor::setRotorPosition(char position) {

    wiring = ROTOR_WIRINGS.at(rotorId - 1);
    currentEntry = ENTRY;

    size_t decalage = ENTRY.find(toupper(position));

    rotate(wiring.begin(), wiring.begin() + decalage, wiring.end());
    rotate(currentEntry.begin(), currentEntry.begin() + decalage, currentEntry.end());
}

bool Rotor::moveRotorNext() {
    rotate(wiring.begin(), wiring.begin() + 1, wiring.end());
    rotate(currentEntry.begin(), currentEntry.begin() + 1, currentEntry.end());

    return notch == currentEntry.front();
}
/*
char Rotor::outputPos(char input) {

    return wiring.at(ENTRY.find(toupper(input)));

}
*/
size_t Rotor::outputPos(size_t position, bool r) {
    if(r){
        return wiring.find(currentEntry.at(position));
    }
    return currentEntry.find(wiring.at(position));
}

char Rotor::outputChar(size_t position, bool r) {
    if(r){
        return currentEntry.at(position);
    }
    return currentEntry.at(position);
}
