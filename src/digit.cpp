#include "..\include\digit.h"
#include <random>

Digit::Digit() : digit(0) {};
Digit::Digit(unsigned char inputDigit, bool firstDigit){
    if(inputDigit > 9) {
        this->digit = 9;
    } else if(inputDigit < 1 && firstDigit) {
        this->digit = 1;
    } else if(inputDigit < 0) {
        this->digit = 0;
    } else{
        this->digit = inputDigit;
    }
};

void Digit::genDigit(bool firstDigit) {
    // Generates a pseudo-random number
    if(firstDigit) {
        this->digit = rand() % 9 + 1;
    } else {
        this->digit = rand() % 10;
    }
}

bool Digit::addDigit(Digit digitToAdd) {
    // Invalid input check
    if(digitToAdd.digit > 9) {
        return false;
    } else if(digitToAdd.digit < 0) {
        return false;
    }

    this->digit += digitToAdd.digit;
    
    // Carry control
    if(this->digit > 10) {
        this->digit = this->digit % 10;
        return true;
    }

    return false;
}