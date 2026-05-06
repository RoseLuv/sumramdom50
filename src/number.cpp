#include "..\include\number.h"
#include <cstdlib>
#include <iostream>

Number::Number() : length(51){
    digits.resize(length, Digit(0, false));
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
    
    digits.resize(this->length, Digit(0, false));
    negative = false;
}

// For testing, not to be used normally...
Number::Number(int length, std::vector<Digit> digits, bool neg) {
    this->length = length;
    this->digits = digits;
    negative = neg;
}

void Number::genNumber() {
    digits.resize(length, Digit(0, false));
    
    // Choose at random the sign
    if(rand() % 2 == 0) {
        negative = true;
    } else {
        negative = false;
    }

    // Generate digits from 0 - 9
    for(int i = 0; i < length - 1; i++) {
        digits[i].genDigit(false);
    }

    // Generate most significant number from 1 - 9
    digits.back().genDigit(true);
}

void addDigitLoop(Number& result, Number secondNumber, int i){
    int j;
    std::vector<Digit>& resultDigits = result.getDigits();
    std::vector<Digit>& secondNumberDigits = secondNumber.getDigits();
    // Add digit from index i. If there is a carry, it returns true.
    // For example: ..1 + ..9 == true and ..1 + ..7 == false
    if(resultDigits[i].addDigit(secondNumberDigits[i])){
            j = 1;
            // Propagating carry, so 1 + 1999 (9991 in memory) is 2000 instead of only 1990
            while(i + j < result.getLength() && resultDigits[i + j].addDigit(Digit(1, false))) {
                j++;
            }
            // Add carry if outside of range (highest digit) so 1 + 999 is 1000 instead of 000
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

    // Subtract digit from index i. If there is a borrow, it returns true.
    // For example: ..7 - ..9 == true and ..7 - ...6 == false
    if(resultDigits[i].subDigit(secondNumberDigits[i])) {
        j = 1;

        // Propagating borrow, so 1007 - 9 (7001 in memory) is 998 instead of 1009
        while(i + j < result.getLength() && resultDigits[i + j].subDigit(Digit(1, false))) {
            j++;
        }
    }
}

Number Number::doOperation(Number secondNumber, bool subtract) {
    // For addition: This has to have at least the lenght of secondNumber.
    // For subtraction: This has to have a higher/equal absolute value
    // See controller.cpp for more info as to how to check it.
    Number result = *this;
    if(secondNumber.getLength() < 1) {
        return result;
    }
    int j;

    // If subtract == false: adds every digit from secondNumber to result
    // If subtract == true: subtracts every digit from result with secondNumber
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

    int i = getLengthWithoutLeading() - 1;
    while(i >= 0) {
            digits[i].printDigit();
            i--;
    }

    std::cout << std::endl;
}

void Number::emptyNumber() {
    // Makes the number == 0
    // So [1,4,0,5] == [0,0,0,0]
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
    // Gets the length of the number without leading zeroes.
    // Useful in cases where, due to subtraction the resulting
    // number got smaller.
    // [2,0,0,0]: length = 4; getLengthWithoutLeading() = 1
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
    // Compares absolute values of number with a secondNumber
    // 1 == secondNumber has bigger abs val
    // 0 == same abs val
    // -1 == number has bigger abs val
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