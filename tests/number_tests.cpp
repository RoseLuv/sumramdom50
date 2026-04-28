#include <assert.h>
#include "../src/digit.cpp"
#include "../src/number.cpp"
#include <vector>
#include <iostream>

void addTwoNumbersSimple() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number 876543210 and 12345678\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;
    for(int i = 0; i < 9; i++) {
        firstDigits.push_back(Digit(i, false));
    }
    Number firstNum(9, firstDigits, false);
    std::cout << "First Number digits: ";
    firstNum.printNumber();
    for(int i = 8; i >= 0; i--) {
        secondDigits.push_back(Digit(i, false));
    }
    Number secondNum(9, secondDigits, false);
    std::cout << "Second Number digits: ";
    secondNum.printNumber();

    for(int i = 0; i < 9; i++) {
        correctResultDigits.push_back(Digit(8, false));
    }
    std::cout << "Second Number digits: ";
    secondNum.addNumber(firstNum);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    
    std::cout << "Expecting: 888888888\n";
    std::cout << "Result: ";

    secondNum.printNumber();
    std::cout << "Assert check\n";
    for(int i = 0; i < 9; i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";
}
/*
void addTwoNumbersWithCarry() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number 00000091 and 0000001\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;
    for(int i = 0; i < 7; i++) {
        firstDigits.push_back(Digit(0, false));
    }
    firstDigits.push_back(Digit(9, false));
    firstDigits.push_back(Digit(1, false));

    Number firstNum(9, firstDigits, false);
    std::cout << "First Number digits:  ";
    firstNum.printNumber();
    for(int i = 7; i > 0; i--) {
        secondDigits.push_back(Digit(0, false));
    }
    secondDigits.push_back(Digit(1, false));
    Number secondNum(8, secondDigits, false);
    std::cout << "Second Number digits: ";
    secondNum.printNumber();

    for(int i = 0; i < 8; i++) {
        correctResultDigits.push_back(Digit(0, false));
    }
    correctResultDigits.push_back(Digit(2, false));
    secondNum.addNumber(firstNum);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    
    std::cout << "Expecting: ";
    for(int i = 8; i >= 0; i--) {
        correctResultDigits[i].printDigit();
    }
    std::cout << "\nResult: ";

    secondNum.printNumber();
    std::cout << "Assert check\n";
    for(int i = 0; i < 9; i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";
}

*/

int main() {
    addTwoNumbersSimple();
    //addTwoNumbersWithCarry();
    return 0;
}