#include "..\include\controller.h"
#include <iostream>

Controller::Controller(Number& resultNumber, Number& calculatingNumber) {
    this->resultNumber = resultNumber;
    this->calculatingNumber = calculatingNumber;
}

void Controller::run() {
    resultNumber.emptyNumber();
    calcResult();
    printResult();
}

void Controller::calcResult() {
    for(int i = 0; i < 50; i++) {
        calculatingNumber.genNumber();
        std::cout << "Number " << i + 1 << ":\n     ";
        calculatingNumber.printNumber();
        if(resultNumber.isNegative() && calculatingNumber.isNegative() ||
            !resultNumber.isNegative() && !calculatingNumber.isNegative()) {
            resultNumber.addNumber(calculatingNumber);
        } else {
            resultNumber.subNumber(calculatingNumber);
            resultNumber.negate();
        }
        calculatingNumber.incLength();
    }
}

void Controller::printResult() {
    int i = 50;
    int numbersPrinted = 0;
    bool digitStarted = false;
    std::cout << "Result:\n     ";
    while(i != 0 && numbersPrinted != 10) {
        if(digitStarted) {
            resultNumber.getDigits()[i].printDigit();
            numbersPrinted++;
        } else if(!digitStarted && resultNumber.getDigits()[i].getDigit() != 0) {
            if(resultNumber.isNegative()) {
                std::cout << '-';
            } else {
                std::cout << '+';
            }
            resultNumber.getDigits()[i].printDigit();
            digitStarted = true;
            numbersPrinted++;
        }
        i--;
    }
    std::cout << '\n';
    std::cout << "Full Result:\n     ";
    resultNumber.printNumber();

}
