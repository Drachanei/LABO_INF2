//
// Created by rhyan on 24/03/2020.
//

#ifndef LABO3_ROTOR_H
#define LABO3_ROTOR_H

#include <vector>
#include <string>
#include <algorithm>

class Rotor {

public:
    Rotor(){};

    void setRotorId(unsigned id);
    void setRotorPosition(char position);

    std::string getRotorId();
    void getRotorConfig();
    char getRotorPos();

    bool moveRotorNext();


    size_t outputPos(size_t position, bool r = false);
    char outputChar(size_t position, bool r = false);

private:
    unsigned rotorId;
    char notch;
    size_t currentPos;
    std::string currentEntry;
    std::string wiring;

    const std::string ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    const std::vector<std::string> ROTOR_WIRINGS = {
            "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
            "AJDKSIRUXBLHWTMCQGZNPYFVOE",
            "BDFHJLCPRTXVZNYEIWGAKMUSQO",
            "ESOVPZJAYQUIRHXLNFTGKDCMWB",
            "VZBRGITYUPSDNHLXAWMJQOFECK"
    };

    const std::vector<char> ROTOR_NOTCH = {
            'Q',
            'E',
            'V',
            'J',
            'Z'
    };



};


#endif //LABO3_ROTOR_H
