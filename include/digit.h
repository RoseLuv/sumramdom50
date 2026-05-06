#pragma once
#include <cstddef>

class Digit{
public:
    Digit();
    Digit(unsigned char digit, bool firstDigit);
    void genDigit(bool firstDigit);
    bool addDigit(Digit secondDigit);
    void printDigit();
    bool subDigit(Digit secondDigit);
    unsigned char getDigit();
private:
    unsigned char digit;
};