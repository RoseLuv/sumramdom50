#pragma once
#include "number.h"

class Controller {
public:
    Controller(Number& num, Number& calculatingNumber);
    void run();
    void printResult();
    void calcResult();
private:    
    Number resultNumber;
    Number calculatingNumber;
};