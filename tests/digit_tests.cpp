#include <assert.h>
#include "../src/digit.cpp"
#include <vector>
#include <iostream>

void addTwoDigitsNoCarry() {
    Digit firstDigit(5, true);
    Digit secondDigit(3, true);
    bool carry = firstDigit.addDigit(secondDigit);
    assert(!carry);
    assert(firstDigit.getDigit() == 8);
    std::cout << "success\n";
}

void addTwoDigitsWithCarry() {
    Digit firstDigit(5, true);
    Digit secondDigit(5, true);
    bool carry = firstDigit.addDigit(secondDigit);
    assert(carry);
    assert(firstDigit.getDigit() == 0);
    std::cout << "success\n";
}

void addTwoDigitsWithOverCarry() {
    Digit firstDigit(5, true);
    Digit secondDigit(8, true);
    bool carry = firstDigit.addDigit(secondDigit);
    assert(carry);
    assert(firstDigit.getDigit() == 3);
    std::cout << "success\n";
}

void subTwoDigitsNoBorrow() {
    Digit firstDigit(5, true);
    Digit secondDigit(3, true);
    bool borrow = firstDigit.subDigit(secondDigit);
    assert(!borrow);
    assert(firstDigit.getDigit() == 2);
    std::cout << "success\n";
}

void subTwoDigitsBorrow() {
    Digit firstDigit(5, true);
    Digit secondDigit(6, true);
    bool borrow = firstDigit.subDigit(secondDigit);
    assert(borrow);
    assert(firstDigit.getDigit() == 9);
    std::cout << "success\n";
}

void subTwoDigitsOverBorrow() {
    Digit firstDigit(5, true);
    Digit secondDigit(9, true);
    bool borrow = firstDigit.subDigit(secondDigit);
    assert(borrow);
    assert(firstDigit.getDigit() == 6);
    std::cout << "success\n";
}

void genDigitTest() {
    Digit firstDigit;
    firstDigit.genDigit(true);

    assert(firstDigit.getDigit() > 0 && firstDigit.getDigit() < 10);
    firstDigit.genDigit(false);
    assert(firstDigit.getDigit() >= 0 && firstDigit.getDigit() < 10);
    std::cout << "success\n";
}

void addSubZero() {
    Digit firstDigit(5, false);
    Digit secondDigit(0, false);

    bool carry = firstDigit.addDigit(secondDigit);
    assert(!carry);
    assert(firstDigit.getDigit() == 5);

    bool borrow = firstDigit.subDigit(secondDigit);
    assert(!borrow);
    assert(firstDigit.getDigit() == 5);
    std::cout << "success\n";
}

void subOneFromZero() {
    Digit firstDigit(0, false);
    Digit secondDigit(1, false);

    bool borrow = firstDigit.subDigit(secondDigit);

    assert(borrow);
    assert(firstDigit.getDigit() == 9);
    std::cout << "success\n";
}

void subEqual() {
    Digit firstDigit(5, false);
    Digit secondDigit(5, false);

    bool borrow = firstDigit.subDigit(secondDigit);

    assert(!borrow);
    assert(firstDigit.getDigit() == 0);
    std::cout << "success\n";
}

void constructorTest() {
    Digit firstDigit(30, false);
    assert(firstDigit.getDigit() == 9);
    Digit secondDigit(0, true);
    assert(secondDigit.getDigit() == 1);
}

int main(){
    addTwoDigitsNoCarry();
    addTwoDigitsWithCarry();
    addTwoDigitsWithOverCarry();
    subTwoDigitsNoBorrow();
    subTwoDigitsBorrow();
    subTwoDigitsOverBorrow();
    genDigitTest();
    addSubZero();
    subOneFromZero();
    subEqual();
    constructorTest();
    return 0;
}