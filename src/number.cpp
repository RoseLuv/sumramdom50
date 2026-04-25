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

    digits.push_back(Digit());
    digits.back().genDigit(true);
    for(int i = 1; i < length; i++) {
        digits.push_back(Digit());
        digits.back().genDigit(false);
    }
}

void Number::addNumber(Number numberToAdd) {
    if (numberToAdd.length > 50 || numberToAdd.length < 1) {
        return;
    } 
    int j;
    // Adds up two digits 
    for(int i = 0; i < numberToAdd.length; i++) {
        // ADD carry functioning 

        if(digits[i].addDigit(numberToAdd.digits[i])){
            digits[i + 1].addDigit(Digit(1, false));
        }
    }
}

void Number::printNumber() {
    for(int i = 0; i < length; i++){
        digits[i].printDigit();
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