#include "..\include\controller.h"

Controller::Controller(Number& num) {
    this->num = num;
}

void Controller::run() {
    Number newNum;
    for(int i = 2; i < 50; i++){
        newNum = Number(i);
        num.addNumber(newNum);
    }
}