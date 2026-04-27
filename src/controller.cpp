#include "..\include\controller.h"

Controller::Controller(Number& num) {
    this->num = num;
}

void Controller::run() {
    Number newNum;
    for(int i = 2; i < 50; i++){
        newNum = Number(i);
        newNum.genNumber();
        if((num.isNegative() && newNum.isNegative()) || 
            !num.isNegative() && !newNum.isNegative()) {
            num.addNumber(newNum);
        } else {
            num.subNumber(newNum);
            num.negate();
            return;
        }
    }
}