#pragma once
#include <cstddef>

class Digit{
public:
    Digit();
    Digit(unsigned char, bool);
    void genDigit(bool);
    bool addDigit(Digit);
    void printDigit();

private:
    unsigned char digit;
};