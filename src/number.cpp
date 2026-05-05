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

void addDigitLoop(Number& result, Number secondNumber, int i){
    int j;
    std::vector<Digit>& resultDigits = result.getDigits();
    std::vector<Digit>& secondNumberDigits = secondNumber.getDigits();
    if(resultDigits[i].addDigit(secondNumberDigits[i])){
            j = 1;
            while(i + j < result.getLength() && resultDigits[i + j].addDigit(Digit(1, false))) {
                j++;
            }
            if(i + j == result.getLength()) {
                result.incLength();
                resultDigits.push_back(Digit(1, true));
            }
        }
}

void subDigitLoop(Number& result, Number secondNumber, int i) {
    int j;
    std::vector<Digit>& resultDigits = result.getDigits();
    std::vector<Digit>& secondNumberDigits = secondNumber.getDigits();
    if(resultDigits[i].subDigit(secondNumberDigits[i])) {
        j = 1;
        while(i + j < result.getLength() && resultDigits[i + j].subDigit(Digit(1, false))) {
            j++;
        }
    }
}

Number Number::doOperation(Number secondNumber, bool subtract) {
    Number result = *this;
    if(secondNumber.getLength() < 1) {
        return result;
    }
    int j;

    for(int i = 0; i < secondNumber.getLength(); i++) {
        if(subtract) {
            subDigitLoop(result, secondNumber, i);  
        } else {
            addDigitLoop(result, secondNumber, i);
        }
    }

    return result;
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
    if(!digitStarted) {
        std::cout << '0';
    }
    std::cout << std::endl;
}

void Number::emptyNumber() {
    digits.assign(length, Digit(0, false));
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

std::vector<Digit>& Number::getDigits() {
    return this->digits;
}

int Number::getLength() {
    return this->length;
}

int Number::getLengthWithoutLeading() {
    int i = this->length - 1;
    while(i > 0) {
        if(digits[i].getDigit() != 0){
            return i + 1;
        }
        i--;
    }
    return 1;
}

int Number::compareAbsWith(Number secondNumber) {
    int lengthWithoutZeroes = getLengthWithoutLeading();

    if(secondNumber.getLength() > lengthWithoutZeroes) {
        return 1;
    } else if(secondNumber.getLength() < lengthWithoutZeroes) {
        return -1;
    }

    std::vector<Digit> calculatingDigits = secondNumber.getDigits();;
    for(int i = lengthWithoutZeroes - 1; i >= 0; i--) {
        if(calculatingDigits[i].getDigit() < digits[i].getDigit() ){
            return -1;
        } else if(calculatingDigits[i].getDigit() > digits[i].getDigit()) {
            return 1;
        }
    }

    return 0;
}