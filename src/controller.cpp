#include "..\include\controller.h"
#include <iostream>

Controller::Controller(Number& resultNumber, Number& calculatingNumber) {
    this->resultNumber = resultNumber;
    this->calculatingNumber = calculatingNumber;
}

void Controller::run() {
    // empties result number so there is no 'garbage' in it
    resultNumber.emptyNumber();
    calcResult();
    printResult();
}

void Controller::calcResult() {
    int absDifference;
    // Adds 50 numbers together
    for(int i = 0; i < 50; i++) {
        // Generate the next number to be added
        calculatingNumber.genNumber();
        //calculatingNumber.printNumber();
        
        // Adds to numbers together if they have the same sign
        // Adds the smaller number to the larger one
        if((resultNumber.isNegative() && calculatingNumber.isNegative()) ||
            (!resultNumber.isNegative() && !calculatingNumber.isNegative())) {
            if(calculatingNumber.getLength() > resultNumber.getLengthWithoutLeading()) {
                resultNumber = calculatingNumber.doOperation(resultNumber, false);
            } else {
                resultNumber = resultNumber.doOperation(calculatingNumber, false); 
            }
        } else {
            // Subtracts two numbers if they have a different sign
            // Subtracts the smaller (abs val) number from the larger one
            absDifference = resultNumber.compareAbsWith(calculatingNumber);
            if(absDifference == 1) {
                resultNumber = calculatingNumber.doOperation(resultNumber, true);
            } else {
                resultNumber = resultNumber.doOperation(calculatingNumber, true);
            }
        }
        // After every loop the calculating number has to get bigger
        calculatingNumber.incLength();
    }
}

void Controller::printResult() {
    int i = resultNumber.getLengthWithoutLeading() - 1;
    int digitsPrinted = 0;
    std::cout << "Result:\n";
    std::vector<Digit> resultNumberDigits = resultNumber.getDigits();
    if(resultNumber.isNegative()) {
        std::cout << '-';
    } else {
        std::cout << '+';
    }
    while(i >= 0 && digitsPrinted != 10) {
        resultNumberDigits[i].printDigit();
        i--;
        digitsPrinted++;
    }
    std::cout << '\n';
    std::cout << "Full Result:\n";
    resultNumber.printNumber();
}

