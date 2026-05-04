#pragma once
#include "number.h"

class Controller {
public:
    Controller(Number& num, Number& calculatingNumber);
    void run();
    void printResult();
    void calcResult();
    int getResultNumActualLength();
    int compareAbs();
private:   
    Number resultNumber;
    Number calculatingNumber;
};