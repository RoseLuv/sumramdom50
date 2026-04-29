#include "..\include\number.h"
#include <cstdlib>
#include <iostream>

Number::Number() : length(51){
    digits.reserve(51);
    negative = false;
}

Number::Number(int length) {
    if(length > 51) {
        this->length = 51;
    } else if(length < 1) {
        this->length = 1;
    } else {
        this->length = length;
    }

    digits.reserve(this->length);
    negative = false;
}

// For testing, not to be used normally...
Number::Number(int length, std::vector<Digit> digits, bool neg) {
    this->length = length;
    this->digits = digits;
    negative = neg;
}

void Number::genNumber() {
    // Change this, its bad, rethink this
    digits.clear();
    digits.reserve(length);
    if(rand() % 2 == 0) {
        negative = true;
    } else {
        negative = false;
    }

    for(int i = 1; i < length; i++) {
        digits.push_back(Digit());
        digits.back().genDigit(false);
    }
    digits.push_back(Digit());
    digits.back().genDigit(true);
}

void Number::addNumber(Number numberToAdd) {
    if (numberToAdd.length > 50 || numberToAdd.length < 1) {
        return;
    } 
    int j;
    // Adds up two digits 
    for(int i = 0; i < numberToAdd.length; i++) {
        if(digits[i].addDigit(numberToAdd.digits[i])){
            j = 1;
            while(i + j < length && digits[i + j].addDigit(Digit(1, false))) {
                j++;
            }
        }
    }
}
// Rename to addPosToNeg???
void Number::subNumber(Number numberToSub) {
    if(numberToSub.length > 50 || numberToSub.length < 1) {
        return;
    }
    int j;
    for(int i = 0; i < numberToSub.length; i++) {
        if(digits[i].subDigit(numberToSub.digits[i])) {
            j = 1;
            while(i + j < numberToSub.length && numberToSub.digits[i + j].subCarry()) {
                j++;
            }
        }
    }
}

void Number::printNumber() {
    if(negative) {
        std::cout << '-';
    } else {
        std::cout << "+"; 
    }
    bool digitStarted = false;
    for(int i = length - 1; i >= 0; i--) {
        if(!digitStarted && digits[i].getDigit() != 0) {
            digits[i].printDigit();
            digitStarted = true;
        } else if(digitStarted) {
            digits[i].printDigit();
        }
    }
    std::cout << std::endl;
}

void Number::emptyNumber() {
    digits.clear();
    digits.reserve(length);
    for(int i = 0; i < length; i++) {
        digits.push_back(Digit());
    }
}

void Number::incLength() {
    if(length + 1 > 51) {
        return;
    }
    length++;
}

bool Number::isNegative() {
    return this->negative;
}

void Number::negate() {
    if(negative) {
        negative = false;
    } else {
        negative = true;
    }
}

std::vector<Digit>& Number::getDigits() {
    return this->digits;
}

