#include <iostream>
#include <string>


#include "Rotor.h"
#include "Reflector.h"
#include "Enigma.h"

using namespace std;

int main() {
    Rotor leftRotor1, middleRotor1, rightRotor1;
    Reflector reflector;

    leftRotor1.setRotorId(2);
    leftRotor1.setRotorPosition('C');
    middleRotor1.setRotorId(4);
    middleRotor1.setRotorPosition('K');
    rightRotor1.setRotorId(1);
    rightRotor1.setRotorPosition('M');


    Enigma enigma1(leftRotor1, middleRotor1, rightRotor1, reflector);

    enigma1.getConfig();

    string textChiffre = "CLZJVMUOAQAGFQJSMOYQLPLCTN";

    for(char& c : textChiffre){
        cout << enigma1.keyboard(c);
    }

    cout << endl;


    Rotor leftRotor2, middleRotor2, rightRotor2;

    leftRotor2.setRotorId(3);
    leftRotor2.setRotorPosition('A');
    middleRotor2.setRotorId(2);
    middleRotor2.setRotorPosition('A');
    rightRotor2.setRotorId(1);
    rightRotor2.setRotorPosition('A');

    Enigma enigma2(leftRotor2, middleRotor2, rightRotor2, reflector);

    enigma2.debug('C');


    system("pause");
    return EXIT_SUCCESS;
}
