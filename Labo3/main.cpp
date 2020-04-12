#include <iostream>
#include <string>


#include "Rotor.h"
#include "Reflector.h"
#include "Enigma.h"

using namespace std;

int main() {
    Rotor leftRotor, middleRotor, rightRotor;
    Reflector reflector;

    leftRotor.setRotorId(2);
    leftRotor.setRotorPosition('C');
    middleRotor.setRotorId(4);
    middleRotor.setRotorPosition('K');
    rightRotor.setRotorId(1);
    rightRotor.setRotorPosition('M');


    //Enigma enigma(leftRotor, middleRotor, rightRotor;

    Enigma enigma(leftRotor, middleRotor, rightRotor, reflector);

    string textChiffre = "CLZJVMUOAQAGFQJSMOYQLPLCTN";

    for(char& c : textChiffre){
        cout << enigma.keyboard(c);

    }

    cout << endl;


    leftRotor.setRotorId(2);
    leftRotor.setRotorPosition('C');
    middleRotor.setRotorId(4);
    middleRotor.setRotorPosition('K');
    rightRotor.setRotorId(1);
    rightRotor.setRotorPosition('M');
    textChiffre = "VIVELINFORMATIQUEALAHEIGVD";

    for(char& c : textChiffre){
        cout << enigma.keyboard(c);

    }


    return 0;
}
