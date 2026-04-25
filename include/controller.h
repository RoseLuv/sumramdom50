#pragma once
#include "number.h"

class Controller {
public:
    Controller(Number& num);
    void run();
    void showResult();
private:    
    Number num;
};