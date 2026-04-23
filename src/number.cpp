#include "number.h"
#include <cstdlib>

Number::Number() : length(1){
    digits.resize(1);
    negative = false;
}

Number::Number(int length) {
    if(length > 50) {
        this->length = 50;
    } else if(length < 1) {
        this->length = 1;
    } else {
        this->length = length;
    }

    digits.resize(this->length);
    negative = false;
}

void Number::genNumber() {
    if(rand() % 2 == 0) {
        negative = true;
    } else {
        negative = false;
    }

    digits[0] = rand() % 9;
    for(int i = 1; i < length - 1; i++) {
        digits[i] = rand() % 9;
    }
}