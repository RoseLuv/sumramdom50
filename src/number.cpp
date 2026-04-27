#include "..\include\number.h"
#include <cstdlib>
#include <iostream>

Number::Number() : length(50){
    digits.reserve(51);
    negative = false;
}

Number::Number(int length) {
    if(length > 50) {
        this->length = 50;
    } else if(length < 1) {
        this->length = 1;
    } else {
        this->length = length;
    }

    digits.reserve(this->length);
    negative = false;
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
            while(digits[i + j].addDigit(Digit(1, false))) {
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
            while(numberToSub.digits[i + j].subCarry()) {
                j++;
            }
        }
    }
}

void Number::printNumber() {
    for(int i = 0; i < length; i++){
        digits[i].printDigit();
    }
    if(negative) {
        std::cout << '-';
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