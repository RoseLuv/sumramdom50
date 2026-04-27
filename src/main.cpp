#include "controller.h"
#include "digit.h"
#include "number.h"
#include <random>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


int main() {
    srand(time(NULL));
    Number toAddNumber = Number(1);
    Number resultNumber = Number();
    resultNumber.emptyNumber();
    /*
    for(int i = 0; i < 50; i++) {
        toAddNumber.genNumber();
        std::cout << "To add number:       ";
        toAddNumber.printNumber();
        std::cout << "ResultNumber before: ";
        resultNumber.printNumber();
        resultNumber.addNumber(toAddNumber);
        std::cout << "ResultNumber after:  ";
        resultNumber.printNumber();
        toAddNumber.incLength();
        toAddNumber.genNumber();
    }
    */
    for(int i = 0; i < 5;i++) {
        toAddNumber.genNumber();
        std::cout << "To add number:       ";
        toAddNumber.printNumber();
        std::cout << "ResultNumber before: ";
        resultNumber.printNumber();
        if(resultNumber.isNegative() && toAddNumber.isNegative() || 
            !resultNumber.isNegative() && !toAddNumber.isNegative()) {
            resultNumber.addNumber(toAddNumber);
        } else {
            resultNumber.subNumber(toAddNumber);
            resultNumber.negate();
        }
        std::cout << "ResultNumber after:  ";
        resultNumber.printNumber();
        toAddNumber.incLength();
        toAddNumber.genNumber();
    }

}