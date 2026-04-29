#include "..\include\digit.h"
#include <random>
#include <iostream>

Digit::Digit() : digit(0) {};
Digit::Digit(unsigned char inputDigit, bool firstDigit){
    if(inputDigit > 9) {
        std::cout << "Invalid Digit! Highest allowed is 9!\nChanging digit value to 9!\n";
        this->digit = 9;
    } else if(inputDigit < 1 && firstDigit) {
        std::cout << "Invalid digit! Digit is first and lower than 0!\n Changing digit to 1!\n";
        this->digit = 1;
    } else if(inputDigit < 0) {
        std::cout << "Invalid digit! Digit is lower than 0!\n Changing digit to 0\n";
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
    if(this->digit >= 10) {
        this->digit = this->digit % 10;
        return true;
    }

    return false;
}

bool Digit::subDigit(Digit digitToSub) {
    if(digitToSub.digit > 9) {
        return false;
        // vvv Should be impossible because it is unsigned...
    } else if (digitToSub.digit < 0 ) {
        return false;
    }
    if(digitToSub.digit > this->digit) {
        this->digit = digitToSub.digit - this->digit;
        return false;
    } 
    if(digitToSub.digit == this->digit) {
        this->digit = 0;
        return false;
    }
    this->digit = 10 + digitToSub.digit - this->digit;
    
    return true;
}

bool Digit::subCarry() {
    if(this->digit == 0) {
        this->digit = 9;
        return true;
    }
    this->digit -= 1;
    return false;
}

void Digit::printDigit() {
    std::cout << char(digit + '0');
}

unsigned char Digit::getDigit() {
    return digit;
}