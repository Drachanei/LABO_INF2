#include <iostream>
#include <string>


#include "Rotor.h"
#include "Reflector.h"
#include "Enigma.h"

using namespace std;

int main() {
    Rotor leftRotor1, middleRotor1, rightRotor1;
    Reflector reflector;


    leftRotor1.setRotorId(3);
    leftRotor1.setRotorPosition('A');
    middleRotor1.setRotorId(2);
    middleRotor1.setRotorPosition('A');
    rightRotor1.setRotorId(1);
    rightRotor1.setRotorPosition('A');


    Enigma enigma1(leftRotor1, middleRotor1, rightRotor1, reflector);

    cout << enigma1.convert('B',true);

/*
    leftRotor1.setRotorId(2);
    leftRotor1.setRotorPosition('C');
    middleRotor1.setRotorId(4);
    middleRotor1.setRotorPosition('K');
    rightRotor1.setRotorId(1);
    rightRotor1.setRotorPosition('M');


    Enigma enigma1(leftRotor1, middleRotor1, rightRotor1, reflector);

    enigma1.getConfig();

    string cipherText = "CLZJVMUOAQAGFQJSMOYQLPLCTN";
    cout << "Cipher Text : " << cipherText << endl << "Plain text : ";
    for(char& c : cipherText){
        cout << enigma1.keyboard(c);
    }

    cout << endl;

    leftRotor1.setRotorId(2);
    leftRotor1.setRotorPosition('C');
    middleRotor1.setRotorId(4);
    middleRotor1.setRotorPosition('K');
    rightRotor1.setRotorId(1);
    rightRotor1.setRotorPosition('M');

    Enigma enigma2(leftRotor1, middleRotor1, rightRotor1, reflector);


    string plainText = "VIVELINFORMATIQUEALAHEIGVD";

    for(char& c : plainText){
        cout << enigma2.convert(c);
    }
*/
    cout << endl;

    return EXIT_SUCCESS;
}
