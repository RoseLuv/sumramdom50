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
private:
    unsigned char digit;
};