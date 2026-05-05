#include <vector>
#pragma once
#include "digit.h"

class Number {
private:
    int length;
    std::vector<Digit> digits;
    bool negative;

public:
    Number();
    Number(int);
    Number(int, std::vector<Digit>, bool);
    void genNumber();
    Number addNumber(Number);
    void printNumber();
    void emptyNumber();
    void incLength();
    bool isNegative();
    Number subNumber(Number);
    void negate();
    std::vector<Digit>& getDigits();
    int getLength();
    int getLengthWithoutLeading();
    int compareAbsWith(Number);
};