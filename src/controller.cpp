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
    int absDifference;
    for(int i = 0; i < 50; i++) {
        calculatingNumber.genNumber();
        calculatingNumber.printNumber();
        if(resultNumber.isNegative() && calculatingNumber.isNegative() ||
            !resultNumber.isNegative() && !calculatingNumber.isNegative()) {
            if(calculatingNumber.getLength() > resultNumber.getLengthWithoutLeading()) {
                resultNumber = calculatingNumber.addNumber(resultNumber);
            } else {
                resultNumber = resultNumber.addNumber(calculatingNumber); 
            }
        } else {
            absDifference = resultNumber.compareAbsWith(calculatingNumber);
            if(absDifference == 1) {
                resultNumber = calculatingNumber.subNumber(resultNumber);
            } else {
                resultNumber = resultNumber.subNumber(calculatingNumber);
            }
        }
        calculatingNumber.incLength();
    }
}

void Controller::printResult() {
    int i = resultNumber.getLengthWithoutLeading() - 1;
    int numbersPrinted = 0;
    bool digitStarted = false;
    std::cout << "Result:\n     ";
    while(i != 0 && numbersPrinted != 10) {
        if(digitStarted) {
            resultNumber.getDigits()[i].printDigit();
            numbersPrinted++;
        } else if(!digitStarted && 
            resultNumber.getDigits()[i].getDigit() >= 0 &&
            resultNumber.getDigits()[i].getDigit() <= 9) {
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
