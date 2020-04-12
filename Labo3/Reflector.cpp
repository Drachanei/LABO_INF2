//
// Created by rhyan on 09/04/2020.
//

#include "Reflector.h"
#include <iostream>
using namespace std;

size_t Reflector::reflect(size_t pos) {



    return wiring.find(ENTRY.at(pos));
}

char Reflector::reflectChar(size_t pos) {
    return ENTRY.at(pos);
}

void Reflector::getReflectorConfig() {
    cout << "reflector      : " << "UKW-B" << endl;
    cout << "entry          : " << ENTRY << endl;
    cout << "wiring         : " << wiring << endl;
}
