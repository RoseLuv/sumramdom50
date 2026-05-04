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
        //std::cout << "Number " << i + 1 << ":\n     ";
        calculatingNumber.printNumber();
        if(resultNumber.isNegative() && calculatingNumber.isNegative() ||
            !resultNumber.isNegative() && !calculatingNumber.isNegative()) {
            //std::cout << "calling r.add.c if both negative or positive\n";
            if(calculatingNumber.getLength() > getResultNumActualLength()) {
                resultNumber = calculatingNumber.addNumber(resultNumber);
            } else {
                resultNumber = resultNumber.addNumber(calculatingNumber); 
            }
        } else {
            absDifference = compareAbs();
            if(absDifference == -1) {
                //std::cout << "calling r.add.c if -1\n";
                resultNumber = resultNumber.subNumber(calculatingNumber);
            } else if(absDifference == 1) {
                //std::cout << "calling c.add.r if 1\n";
                resultNumber = calculatingNumber.subNumber(resultNumber);
            } else {
                //std::cout << "calling c.add.r if 0\n";
                resultNumber = resultNumber.subNumber(calculatingNumber);
            }
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

int Controller::getResultNumActualLength() {
    int i =resultNumber.getDigits().size() - 1;
    while(i > 0) {
        if(resultNumber.getDigits()[i].getDigit() != 0){
            return i + 1;
        }
        i--;
    }
    return 1;
} 

int Controller::compareAbs(){
    int resultNumLength = getResultNumActualLength();
    if(calculatingNumber.getLength() > resultNumLength) {
        return 1;
    } else if(calculatingNumber.getLength() < resultNumLength) {
        return -1;
    }

    std::vector<Digit> calculatingDigits = calculatingNumber.getDigits();
    std::vector<Digit> resultDigits = resultNumber.getDigits();
    for(int i = resultNumLength - 1; i >= 0; i--) {
        if(calculatingDigits[i].getDigit() < resultDigits[i].getDigit() ){
            return -1;
        } else if(calculatingDigits[i].getDigit() > resultDigits[i].getDigit()) {
            return 1;
        }
    }
    return 0;
}
