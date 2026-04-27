#pragma once
#include <cstddef>

class Digit{
public:
    Digit();
    Digit(unsigned char, bool);
    void genDigit(bool);
    bool addDigit(Digit);
    void printDigit();
    bool subDigit(Digit);
    bool subCarry();
    unsigned char getDigit();
private:
    unsigned char digit;
};