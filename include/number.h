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
    void genNumber();
    void addNumber(Number);
    void printNumber();
    void emptyNumber();
    void incLength();
};