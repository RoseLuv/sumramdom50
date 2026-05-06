#include "..\include\digit.h"
#include <random>
#include <iostream>

Digit::Digit() : digit(0) {};
Digit::Digit(unsigned char inputDigit, bool firstDigit){
    if(inputDigit > 9) {
        //std::cout << "Invalid Digit! Highest allowed is 9!\nChanging digit value to 9!\n";
        this->digit = 9;
    } else if(inputDigit < 1 && firstDigit) {
        //std::cout << "Invalid digit! Digit is first and lower than 0!\n Changing digit to 1!\n";
        this->digit = 1;
    } else{
        this->digit = inputDigit;
    }
};

void Digit::genDigit(bool firstDigit) {
    // Generates a pseudo-random digit
    if(firstDigit) {
        this->digit = rand() % 9 + 1;
    } else {
        this->digit = rand() % 10;
    }
}

bool Digit::addDigit(Digit secondDigit) {
    // adds secondDigit to this-:digit
    // returns true if there is a carry
    // false otherwise


    // Invalid input check
    if(secondDigit.digit > 9) {
        return false;
    }

    this->digit += secondDigit.digit;
    
    // Carry control
    if(this->digit >= 10) {
        this->digit = this->digit % 10;
        return true;
    }

    return false;
}

bool Digit::subDigit(Digit secondDigit) {
    // subtracts two digits together
    // returns true if there is a borrow needed
    // false otherwise

    if (secondDigit.digit > 9) {
        return false;
    } 

    if (this->digit >= secondDigit.digit) {
        this->digit = this->digit - secondDigit.digit;
        return false; 
    }

    this->digit = 10 + this->digit - secondDigit.digit;
    return true;
}


void Digit::printDigit() {
    std::cout << char(digit + '0');
}

unsigned char Digit::getDigit() {
    return digit;
}