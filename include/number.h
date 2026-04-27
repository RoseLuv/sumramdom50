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
    void addNumber(Number);
    void printNumber();
    void emptyNumber();
    void incLength();
    bool isNegative();
    void subNumber(Number);
    void negate();
    void pushIntoDigits(unsigned char);
    const std::vector<Digit>& getDigits();
};