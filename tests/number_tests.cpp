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
    secondNum = secondNum.doOperation(firstNum, false);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    
    std::cout << "Expecting: 888888888\n";
    std::cout << "Result: ";

    secondNum.printNumber();
    std::cout << "Assert check\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: Correct sign\n";
    assert(!secondNum.isNegative());
    std::cout << "Assert check passed!\n";
}

void addTwoNumbersWithCarry() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number 19000000 and 1000000\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;
    for(int i = 0; i < 6; i++) {
        firstDigits.push_back(Digit(0, false));
    }
    firstDigits.push_back(Digit(9, false));
    firstDigits.push_back(Digit(1, false));

    Number firstNum(firstDigits.size(), firstDigits, false);
    std::cout << "First Number digits:  ";
    firstNum.printNumber();
    for(int i = 0; i < 6; i++) {
        secondDigits.push_back(Digit(0, false));
    }
    secondDigits.push_back(Digit(1, false));
    secondDigits.push_back(Digit(0, false));
    Number secondNum(secondDigits.size(), secondDigits, false);
    std::cout << "Second Number digits: ";
    secondNum.printNumber();

    for(int i = 0; i < 7; i++) {
        correctResultDigits.push_back(Digit(0, false));
    }
    correctResultDigits.push_back(Digit(2, false));
    secondNum = secondNum.doOperation(firstNum, false);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    
    std::cout << "Expecting: ";
    for(int i = 7; i >= 0; i--) {
        correctResultDigits[i].printDigit();
    }
    std::cout << "\nResult: ";

    secondNum.printNumber();
    std::cout << "Assert check: Correct numbers\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: Correct sign\n";
    assert(!secondNum.isNegative());
    std::cout << "Assert check passed!\n";
}

void multipleCarryTest() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number 999 and 1\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;

    for(int i = 0; i < 3; i++) {
        firstDigits.push_back(Digit(9, false));
    }

    Number firstNum(firstDigits.size(), firstDigits, false);
    std::cout << "First Number digits: ";
    firstNum.printNumber();

    secondDigits.push_back(Digit(1, false));
    for(int i = 0; i < 3; i++) {
        secondDigits.push_back(Digit(0, false));
    }

    Number secondNum(secondDigits.size(), secondDigits, false);
    std::cout << "Second Number digits: ";
    secondNum.printNumber();


    for(int i = 0; i < 3; i++) {
        correctResultDigits.push_back(Digit(0, false));
    }
    correctResultDigits.push_back(Digit(1, false));

    std::cout << "Expecting: ";
    for(int i = correctResultDigits.size() - 1; i >= 0; i--) {
        correctResultDigits[i].printDigit();
    }
    std::cout << "\nResult: ";
    secondNum = secondNum.doOperation(firstNum, false);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    secondNum.printNumber();

    std::cout << "Assert check: Correct Digits\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: Correct sign\n";
    assert(!secondNum.isNegative());
    std::cout << "Assert check passed!\n";
}

void subPosToNeg() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number 19 and -5\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;

    firstDigits.push_back(Digit(9, false));
    firstDigits.push_back(Digit(1, false));
    Number firstNum(firstDigits.size(), firstDigits, false);

    secondDigits.push_back(Digit(5, false));
    secondDigits.push_back(Digit(0, false));
    Number secondNum(secondDigits.size(), secondDigits, true);

    correctResultDigits.push_back((Digit(4, false)));
    correctResultDigits.push_back((Digit(1, false)));

    std::cout << "First Number digits: ";
    firstNum.printNumber();
    std::cout << "Second Number digits: ";
    secondNum.printNumber();
    std::cout << "Expecting: ";
    for(int i = correctResultDigits.size() - 1; i >= 0; i--) {
        correctResultDigits[i].printDigit();
    }

    std::cout << "\nResult: ";
    secondNum = firstNum.doOperation(secondNum, true);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    secondNum.printNumber();

    std::cout << "Assert check: Correct digits\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";


    std::cout << "Assert check: Correct sign\n";
    assert(!secondNum.isNegative());
    std::cout << "Assert check passed!\n";
}

void subNegToPos() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number -19 and 5\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;
    firstDigits.push_back(Digit(9, false));
    firstDigits.push_back(Digit(1, false));
    
    Number firstNum(firstDigits.size(), firstDigits, true);
    secondDigits.push_back(Digit(5, false));
    secondDigits.push_back(Digit(0, false));
    Number secondNum(secondDigits.size(), secondDigits, false);

    correctResultDigits.push_back(Digit(4, false));
    correctResultDigits.push_back(Digit(1, false));
    
    std::cout << "First Number digits: ";
    firstNum.printNumber();
    std::cout << "Second Number digits: ";
    secondNum.printNumber();
    std::cout << "Expecting: ";
    for(int i = correctResultDigits.size() - 1; i >= 0; i--) {
        correctResultDigits[i].printDigit();
    }

    std::cout << "\nResult: ";
    secondNum = firstNum.doOperation(secondNum, true);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    secondNum.printNumber();

    std::cout << "Assert check: Correct digits\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: Correct sign\n";
    assert(secondNum.isNegative());
    std::cout << "Assert check passed!\n";

}

void addNumToZero() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number 10 and 0\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;

    firstDigits.push_back(Digit(0, false));
    firstDigits.push_back(Digit(1, false));
    secondDigits.push_back(Digit(0, false));
    secondDigits.push_back(Digit(0, false));

    Number firstNum(firstDigits.size(), firstDigits, false);
    Number secondNum(secondDigits.size(), secondDigits, false);

    correctResultDigits.push_back(Digit(0, false));
    correctResultDigits.push_back(Digit(1, false));

    std::cout << "First Number digits: ";
    firstNum.printNumber();
    std::cout << "Second Number digits: ";
    secondNum.printNumber();
    std::cout << "Expecting: ";
    for(int i = correctResultDigits.size() - 1; i >= 0; i--) {
        correctResultDigits[i].printDigit();
    }

    std::cout << "\nResult: ";
    secondNum = secondNum.doOperation(firstNum, false);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    secondNum.printNumber();

    std::cout << "Assert check: Correct digits\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: Correct sign\n";
    assert(!secondNum.isNegative());
    std::cout << "Assert check passed!\n";

}

void addTwoNegNumbersSimple() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number -876543210 and -12345678\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;
    for(int i = 0; i < 9; i++) {
        firstDigits.push_back(Digit(i, false));
    }
    Number firstNum(9, firstDigits, true);
    std::cout << "First Number digits: ";
    firstNum.printNumber();
    for(int i = 8; i >= 0; i--) {
        secondDigits.push_back(Digit(i, false));
    }
    Number secondNum(9, secondDigits, true);
    std::cout << "Second Number digits: ";
    secondNum.printNumber();

    for(int i = 0; i < 9; i++) {
        correctResultDigits.push_back(Digit(8, false));
    }
    std::cout << "Second Number digits: ";
    secondNum = secondNum.doOperation(firstNum, false);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    
    std::cout << "Expecting: 888888888\n";
    std::cout << "Result: ";

    secondNum.printNumber();
    std::cout << "Assert check\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: Correct sign\n";
    assert(secondNum.isNegative());
    std::cout << "Assert check passed!\n";
}

void addNegToPosHeavyCarry() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number +1000 and -1\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    for(int i = 0; i < 3; i++) {
        firstDigits.push_back(Digit(0, false));
    }
    firstDigits.push_back(Digit(1, true));

    secondDigits.push_back(Digit(1, true));

    Number firstNumber(firstDigits.size(), firstDigits, false);
    Number secondNumber(secondDigits.size(), secondDigits, true);

    firstNumber = firstNumber.doOperation(secondNumber, true);
    firstNumber.printNumber();

    for(int i = 0; i < firstNumber.getLengthWithoutLeading(); i++) {
        assert(firstNumber.getDigits()[i].getDigit() == 9);
    }

}

void addTwoNegNumbersWithCarry() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Add Two Numbers\nCombine number -19000000 and -1000000\n";
    std::vector<Digit> firstDigits;
    std::vector<Digit> secondDigits;
    std::vector<Digit> correctResultDigits;
    for(int i = 0; i < 6; i++) {
        firstDigits.push_back(Digit(0, false));
    }
    firstDigits.push_back(Digit(9, false));
    firstDigits.push_back(Digit(1, false));

    Number firstNum(firstDigits.size(), firstDigits, true);
    std::cout << "First Number digits:  ";
    firstNum.printNumber();
    for(int i = 0; i < 6; i++) {
        secondDigits.push_back(Digit(0, false));
    }
    secondDigits.push_back(Digit(1, false));
    secondDigits.push_back(Digit(0, false));
    Number secondNum(secondDigits.size(), secondDigits, true);
    std::cout << "Second Number digits: ";
    secondNum.printNumber();

    for(int i = 0; i < 7; i++) {
        correctResultDigits.push_back(Digit(0, false));
    }
    correctResultDigits.push_back(Digit(2, false));
    secondNum = secondNum.doOperation(firstNum, false);
    std::vector<Digit> resultDigits = secondNum.getDigits();
    
    std::cout << "Expecting: ";
    for(int i = 7; i >= 0; i--) {
        correctResultDigits[i].printDigit();
    }
    std::cout << "\nResult: ";

    secondNum.printNumber();
    std::cout << "Assert check: Correct numbers\n";
    for(int i = 0; i < correctResultDigits.size(); i++) {
        assert(correctResultDigits[i].getDigit() == resultDigits[i].getDigit());
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: Correct sign\n";
    assert(secondNum.isNegative());
    std::cout << "Assert check passed!\n";
}

void constructorLengthHigh() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Constructor length is too high\n";
    Number testNumber(100);
    std::cout << "Assert check: Length == 51\n";
    assert(testNumber.getLength() == 51);
    std::cout << "Assert check passed!\n";
}

void constructorLengthLow() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: Constructor length is too low\n";
    Number testNumber(-100);
    std::cout << "Assert check: Length == 1\n";
    assert(testNumber.getLength() == 1);
    std::cout << "Assert check passed!\n";
}

void incLengthTest() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: incLength()\n";
    Number testNumber(10);
    int prevLength = testNumber.getLength();
    std::cout << "Number Length: " << prevLength << "\n";
    testNumber.incLength();
    std::cout << "Number Length after inc: " << testNumber.getLength() << "\n"; 
    std::cout << "Assert check: curLength == 11 and prevLength == 10\n";
    assert(testNumber.getLength() == 11 && prevLength == 10);
    std::cout << "Assert check passed!\n";

    Number testNumber2(51);
    prevLength = testNumber2.getLength();
    std::cout << "2. Number Length: " << prevLength << "\n";
    testNumber2.incLength();
    std::cout << "2. Number Length after inc: " << testNumber2.getLength() << "\n"; 
    std::cout << "Assert check: curLength == 51 and prevLength == 51\n";
    assert(testNumber2.getLength() == 51 && prevLength == 51);
    std::cout << "Assert check passed!\n";

}

void genNumberTest() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: genNumber()\n";
    Number testNumber(5);
    testNumber.genNumber();
    std::vector<Digit> digits = testNumber.getDigits();
    
    std::cout << "Testing Number: ";
    testNumber.printNumber();

    std::cout << "Assert check: digits size == number length\n";
    assert(digits.size() == testNumber.getLength());
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: correct digits. >= 0 && <= 9\n";
    for(int i = 0; i < digits.size(); i++) {
        assert(digits[i].getDigit() >= 0 && digits[i].getDigit() <= 9);
    }
    std::cout << "Assert check passed!\n";

    std::cout << "Assert check: first digit is correct. >= 1\n";
    assert(digits[digits.size() - 1].getDigit() >= 1);
    std::cout << "Assert check passed!\n";
}

void emptyNumberTest() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: emptyNumber()\n";

    Number testnumber(5);
    testnumber.emptyNumber();
    std::cout << "Assert check: all numbers == 0\n";
    for(int i = 0; i < testnumber.getLength(); i++) {
        assert(testnumber.getDigits()[i].getDigit() == 0);
    }
    std::cout << "Assert check passed!\n";
}

void getLengthWithoutLeadingTest() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: getLengthWithoutLeading\n";
    std::vector<Digit> testDigits;
    for(int i = 0; i < 10; i++) {
        testDigits.push_back(Digit(0, false));
    }
    Number testNumber(testDigits.size(), testDigits, false);
    assert(testNumber.getLengthWithoutLeading() == 1);

    testDigits.clear();
    testDigits.push_back(Digit(1, false));
    for(int i = 0; i < 10; i++) {
        testDigits.push_back(Digit(0, false));
    }

    testNumber = Number(testDigits.size(), testDigits, false);
    assert(testNumber.getLengthWithoutLeading() == 1);

    testDigits.clear();
    for(int i = 0; i < 3; i++){
        testDigits.push_back(Digit(i, false));
    }
    for(int i = 0; i < 10; i++) {
        testDigits.push_back(Digit(0, false));
    }

    testNumber = Number(testDigits.size(), testDigits, false);
    assert(testNumber.getLengthWithoutLeading() == 3);
}

void compareAbsWithTest() {
    std::cout << "------------------------------------------------------------------\n";
    std::cout << "Testing: compareAbsWith\n";
    std::vector<Digit> firstDigit;
    std::vector<Digit> secondDigit;

    for(int i = 0; i < 10; i++){
        firstDigit.push_back(Digit(i, false));
        secondDigit.push_back(Digit(10 - i, false));
    }

    Number firstNumber(firstDigit.size(), firstDigit, false);
    Number secondNumber(secondDigit.size(), secondDigit, false);

    assert(firstNumber.compareAbsWith(secondNumber) == -1);
    assert(secondNumber.compareAbsWith(firstNumber) == 1);

    firstDigit.clear();
    secondDigit.clear();
    for(int i = 0; i < 5; i++) {
        firstDigit.push_back(Digit(1, false));
        secondDigit.push_back(Digit(1, false));
    }

    firstNumber = Number(firstDigit.size(), firstDigit, false);
    secondNumber = Number(secondDigit.size(), secondDigit, false);

    assert(firstNumber.compareAbsWith(secondNumber) == 0);
    assert(secondNumber.compareAbsWith(firstNumber) == 0);
}


int main() {
    srand(time(NULL));
    addTwoNumbersSimple();
    addTwoNumbersWithCarry();
    multipleCarryTest();
    subPosToNeg();
    subNegToPos();
    addNumToZero();
    addTwoNegNumbersSimple();
    addTwoNegNumbersWithCarry();
    constructorLengthHigh();
    constructorLengthLow();
    incLengthTest();
    genNumberTest();
    emptyNumberTest();
    addNegToPosHeavyCarry();
    getLengthWithoutLeadingTest();
    compareAbsWithTest();
    std::cout << "All passed!\n";
    return 0;
}