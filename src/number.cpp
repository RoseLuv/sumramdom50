#include "..\include\number.h"
#include <cstdlib>

Number::Number() : length(1){
    digits.resize(1);
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

    digits.resize(this->length, Digit(0, false));
    negative = false;
}

void Number::genNumber() {
    if(rand() % 2 == 0) {
        negative = true;
    } else {
        negative = false;
    }

    digits[0].genDigit(true);
    for(int i = 1; i < length - 1; i++) {
        digits[i].genDigit(false);
    }
}

bool Number::addNumber(Number numberToAdd) {
    if (numberToAdd.length > 50) {
        return;
    } 
    if (numberToAdd.length < 1) {
        return;
    }
    int j;
    // Adds up two digits 
    for(int i = 0; i < numberToAdd.length - 1; i++) {
        // ADD carry functioning 

        if(digits[i].addDigit(numberToAdd.digits[i])){
            digits[i + 1].addDigit(Digit(1, false));
        }
    }
}